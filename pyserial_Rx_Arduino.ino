const int BUFFER_SIZE = 10; // PythonCommand <xx>
char buf[BUFFER_SIZE];

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
}

void loop() {
  String motion;
  if (Serial.available() > 0) {
    int rlen = Serial.readBytes(buf, BUFFER_SIZE);
    if (buf[0] == '<') {
      for (int i = 1; i < rlen; i++) {
        if (buf[i] == '>') {
          //Serial.println(motion);
          break;
        }
        else {
          motion += String(buf[i]);
        }
      }
    }
    if (motion == "HIGH") {
      Serial.println("Received HIGH");
      digitalWrite(13, HIGH);
    }
    if (motion == "LOW") {
      Serial.println("Received LOW");
      digitalWrite(13, LOW);
    }
  }
}
