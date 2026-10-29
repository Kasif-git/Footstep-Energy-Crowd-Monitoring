#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID   "TMPL3OjDoD2y2"
#define BLYNK_TEMPLATE_NAME "Stampede alert"
#define BLYNK_AUTH_TOKEN    "FJbSnOwTAyUonyHCzcwrl7QP4AGC9sIO"

#include <WiFi.h>
#include <BlynkSimpleEsp32.h>

// ------------------- WIFI -------------------
const char* ssid = "1";
const char* password = "11223344";

// ------------------- PIEZO ------------------
const int piezoPin = 35;
const int STEP_THRESHOLD = 4000;

unsigned long lastStepTime = 0;
const unsigned long STEP_LOCKOUT = 350;

int stepCount = 0;

// ------------------- STEP WINDOW (5 sec) ----
unsigned long windowStartTime = 0;
int stepsInWindow = 0;

// ------------------- ALERT ------------------
const int STEP_WINDOW_THRESHOLD = 5; // more than 5 steps
const unsigned long WINDOW_DURATION = 5000; // 5 seconds
bool alertSent = false;

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("Connecting to WiFi...");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  Serial.println("Connecting to Blynk...");
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, password);

  Serial.println("Peak-Based Footstep Detection Started");

  windowStartTime = millis();
}

void loop() {
  Blynk.run();

  int piezoValue = analogRead(piezoPin);
  unsigned long now = millis();

  // Send raw piezo value to Blynk
  Blynk.virtualWrite(V3, piezoValue);

  // ---------------- YOUR ORIGINAL STEP LOGIC ----------------
  if (piezoValue > STEP_THRESHOLD &&
      (now - lastStepTime) > STEP_LOCKOUT) {

    stepCount++;
    stepsInWindow++;
    lastStepTime = now;

    Serial.print("STEP DETECTED! Total Steps: ");
    Serial.println(stepCount);

    Blynk.virtualWrite(V1, stepCount);

    // Wait until vibration settles
    while (analogRead(piezoPin) > STEP_THRESHOLD) {
      delay(2);
    }
  }

  // ---------------- 5-SECOND ALERT CHECK ----------------
  if (now - windowStartTime >= WINDOW_DURATION) {

    Serial.print("Steps in last 5 sec: ");
    Serial.println(stepsInWindow);

    if (stepsInWindow > STEP_WINDOW_THRESHOLD && !alertSent) {
      Blynk.virtualWrite(V4, 1);
      Blynk.logEvent("crowd_alert",
                     "⚠️ Crowd surge detected: >5 steps in 5 seconds");
      alertSent = true;
    }

    if (stepsInWindow <= STEP_WINDOW_THRESHOLD) {
      Blynk.virtualWrite(V4, 0);
      alertSent = false;
    }

    // Reset window
    stepsInWindow = 0;
    windowStartTime = now;
  }

  delay(5);
}
