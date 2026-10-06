#include <ESP8266WiFi.h>

// Define motor control pins
const int IN1 = D1;
const int IN2 = D2;
const int IN3 = D3;
const int IN4 = D4;

// Replace with your network credentials
const char* ssid = "YOUR_WIFI_NAME";
const char* password = "YOUR_WIFI_PASSWORD";

WiFiServer server(80);

void setup() {
  // Set the motor control pins as outputs
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Initialize the serial communication
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to Wi-Fi. IP address: ");
  Serial.println(WiFi.localIP());

  // Start the server
  server.begin();
}

void loop() {
  WiFiClient client = server.available();
  if (client) {
    String request = client.readStringUntil('\r');
    client.flush();

    // Control the car based on the request
    if (request.indexOf("/forward") != -1) {
      moveForward();
    } else if (request.indexOf("/backward") != -1) {
      moveBackward();
    } else if (request.indexOf("/left") != -1) {
      turnLeft();
    } else if (request.indexOf("/right") != -1) {
      turnRight();
    } else if (request.indexOf("/stop") != -1) {
      stopCar();
    }


    client.println("HTTP/1.1 200 OK");
    client.println("Content-Type: text/html");
    client.println("");
    client.println("<!DOCTYPE HTML>");
    client.println("<html>");
    client.println("<head>");
    client.println("<title>DUCK - MOBILE</title>");
    client.println("<style>");
    client.println("body { font-family: Arial, sans-serif; text-align: center; margin-top: 50px; background-color: #ffff9d; }");
    client.println("h1 { color: #333; }");
    client.println(".button-container { display: flex; flex-direction: column; align-items: center; }");
    client.println(".button-row { display: flex; justify-content: center; gap: 20px; margin: 10px 0; }");
    client.println("button { font-size: 20px; width: 100px; height: 100px; background-color: #207B00; color: white; border: none; border-radius: 5px; cursor: pointer; display: flex; align-items: center; justify-content: center; }");
    client.println("button:hover { background-color: #165700; }");
    client.println(".stop-button { background-color: #FF2600; width: 100px; height: 100px; }");
    client.println(".stop-button:hover { background-color: #B22A00; }");
    client.println("</style>");
    client.println("</head>");
    client.println("<body>");
    client.println("<h1>&#x1F986; DUCK-MOBILE &#x1F986;</h1>");
    client.println("<div class=\"button-container\">");

    // Forward button
    client.println("<div class=\"button-row\">");
    client.println("<button onclick=\"location.href='/forward'\"> &#9650; </button>");
    client.println("</div>");

    // Left, Stop, Right buttons in a row
    client.println("<div class=\"button-row\">");
    client.println("<button onclick=\"location.href='/left'\"> &#9664; </button>");
    client.println("<button class=\"stop-button\" onclick=\"location.href='/stop'\">&#9724;</button>");
    client.println("<button onclick=\"location.href='/right'\"> &#9654; </button>");
    client.println("</div>");

    // Backward button
    client.println("<div class=\"button-row\">");
    client.println("<button onclick=\"location.href='/backward'\"> &#9660; </button>");
    client.println("</div>");

    client.println("</div>"); // End of button-container
    client.println("</body>");
    client.println("</html>");
    client.stop();
  }
}

void moveForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void moveBackward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopCar() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
