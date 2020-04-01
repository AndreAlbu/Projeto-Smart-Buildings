//Importação das bibliotecas

#include <ESP8266WiFi.h>         //Comunicação WiFi
#include <ESP8266WebServer.h>   //Biblioteca para criação do servidor
#include <DHT.h>               //Biblioteca para o sensor de temperatura e umidade
#include <Adafruit_Sensor.h>  //Biblioteca para o sensor de temperatura e umidade
#include <IRremoteESP8266.h> //INCLUSÃO DE BIBLIOTECA

//Mapeamento de pinos do NodeMCU ESP8266
//+
//+
  #define D0    16
  #define D1    5
  #define D2    4
  #define D3    0
  #define D4    2
  #define D5    14
  #define D6    12
  #define D7    13
  #define D8    15
  #define D9    3
  #define D10   1

  #define DHTPIN D3
  #define DHTTYPE DHT11 // O sensor é o dht11 
  
  DHT dht(DHTPIN,DHTTYPE);
//- 
//-
//-


IRsend emissorIR(4);

int tam = 83;
int frequencia = 38;

int temp = 16;

//Botão liga
unsigned int Ligar[83] = {9050,4500, 500,550, 550,550, 500,600, 500,1700, 450,600, 500,600, 500,600, 500,600, 450,1700, 500,650, 450,1700, 500,600, 450,1700, 
                          500,600, 500,600, 500,600, 450,650, 450,650, 450,600, 500,1750, 400,650, 500,600, 450,600, 500,650, 450,600, 500,600, 500,600,500,
                          600, 450,1700, 500,600, 500,600, 500,600, 450,600, 500,650, 450,1700, 500,1700, 450,600, 500,600, 500,600, 500,600, 450};

//Botão desliga
unsigned int Desligar[83] = {9100,4450, 500,600, 500,600, 450,600, 500,650, 450,600, 500,600, 500,600, 450,650, 450,1700, 500,600, 500,1700, 450,650, 450,1700, 
                             500,600, 450,650, 450,650, 450,600, 500,600, 500,600, 500,1700, 450,600, 500,600, 500,600, 500,600, 450,650, 500,600, 450,600,500,
                             600, 500,1700, 500,600, 450,650, 450,650, 450,600, 500,600, 500,1700, 450,1750, 450,600, 500,600, 500,600, 450,650, 450};

//Temp 16:

unsigned int Temp_16[83] = {9000,4500, 450,600, 500,600, 500,600, 500,600, 450,600, 500,650, 450,600, 500,600, 450,1700, 500,600, 500,550, 550,600, 450,1700, 
                            500,600, 450,600, 500,650, 450,600, 500,600, 450,600, 500,1700, 500,550, 550,600, 450,600, 500,600, 500,550, 550,600, 450,600, 500,
                            600, 500,1700, 500,600, 450,600, 500,600, 500,550, 550,600, 450,1700, 500,1700, 450,600, 500,600, 500,550, 550,600, 450};

//Temp 17:

unsigned int Temp_17[83] = {9000,4500, 500,550, 500,600, 500,550, 550,1700, 450,600, 500,600, 450,600, 500,650, 450,600, 500,1700, 450,600, 500,600, 500,1700, 
                            450,650, 450,600, 500,600, 450,650, 450,650, 450,600, 500,1700, 450,600, 500,650, 450,600, 500,600, 450,600, 500,650, 450,600, 500,
                            600, 450,1750, 450,600, 500, 600, 500,600, 450,600, 500,600, 500,1700, 450,1750, 450,600, 500,600, 450,600, 500,650, 450};

//Temp 18:

unsigned int Temp_18[83] = {9050,4450, 600,500, 550,550, 550,500, 550,1650, 500,600, 500,600, 450,600, 500,600, 500,1700, 450,1700, 500,600, 500,600, 450,1700, 
                            500,600, 450,650, 450,600, 500,600, 500,600, 450,650, 450,1700, 500,600, 500,550, 500,600, 500,600, 500,600, 500,550, 500,600, 500,
                            600, 500,1700, 500,550, 500,600, 500,600, 500,600, 500,550, 500,1700, 500,1650, 500,600, 500,600, 500,600, 500,550, 500};

//Temp 19:

unsigned int Temp_19[83] = {9000,4500, 500,600, 450,650, 450,600, 500,1700, 450,600, 500,600, 500,550, 550,600, 450,600, 500,600, 500,1700, 450,650, 450,1700, 
                            500,600, 450,600, 500,600, 500,550, 550,600, 450,600, 500,1700, 500,550, 500,650, 450,600, 500,600, 500,550, 550,600, 450,600, 500,
                            600, 500,1650, 500,600, 500,600, 500,600, 450,600, 500,600, 500,1650, 550,1700, 450,600, 500,600, 450,600, 500,600, 500};

//Temp 20:

unsigned int Temp_20[83] = {9000,4500, 450,600, 500,600, 450,600, 500,1750, 450,600, 500,600, 450,600, 500,600, 500,1700, 450,650, 450,1700, 500,600, 450,1700, 
                            500,600, 500,550, 500,650, 450,600, 500,600, 450,600, 500,1700, 500,600, 500,600, 450,600, 500,600, 500,550, 550,600, 450,600, 500,
                            600, 500,1700, 450,650, 450,600, 500,600, 450,600, 500,650, 450,1700, 500,1700, 450,600, 500,600, 450,600, 500,650, 450};

//Temp 21:

unsigned int Temp_21[83] = {9050,4500, 450,600, 500,600, 450,650, 450,1700, 500,600, 500,600, 450,600, 500,600, 500,600, 500,1700, 450,1700, 500,600, 450,1700, 
                            500,600, 500,550, 500,650, 450,600, 500,600, 450,650, 450,1750, 450,600, 500,600, 450,600, 500,600, 500,550, 550,600, 450,600, 500,
                            600, 500,1700, 450,650, 450,600, 500,600, 500,550, 550,600, 450,1700, 500,1700, 450,600, 500,600, 500,550, 550,550, 500};

//Temp 22:

unsigned int Temp_22[83] = {9050,4450, 550,550, 450,650, 450,600, 450,1750, 450,650, 450,650, 400,650, 450,650, 450,1700, 500,1700, 500,1650, 500,600, 450,1700, 
                            500,650, 400,650, 450,650, 400,700, 400,700, 400,650, 450,1750, 450,650, 400,700, 400,650, 450,650, 400,700, 400,700, 400,650, 450,
                            650, 400,1750, 500,600, 450,650, 400,700, 400,650, 450,650, 450,1700, 500,1700, 500,600, 450,650, 400,700, 400,700, 350};

//Temp 23:

unsigned int Temp_23[83] = {9000,4500, 450,600, 500,600, 500,600, 500,1650, 500,600, 500,600, 450,600, 500,600, 500,600, 500,600, 450,650, 450,1700, 500,1650, 
                            500,600, 500,600, 500,600, 450,600, 500,600, 500,600, 500,1700, 450,600, 500,600, 500,600, 500,600, 450,600, 500,600, 500,600, 500,
                            600, 450,1700, 500,600, 500,550, 550,550, 500,600, 500,600, 500,1650, 500,1700, 500,550, 500,650, 450,600, 500,600, 500};

//Temp 24:

unsigned int Temp_24[83] = {9000,4500, 450,600, 500,600, 450,650, 450,1750, 450,600, 500,600, 450,650, 450,650, 450,1700, 450,650, 450,600, 500,1700, 450,1700, 
                            500,650, 450,600, 450,650, 450,600, 500,600, 500,600, 450,1750, 450,600, 500,600, 450,650, 450,650, 450,600, 500,600, 450,650, 450,
                            650, 450,1700, 500,600, 450,600, 500,650, 450,600, 500,600, 450,1700, 500,1700, 450,650, 450,650, 450,600, 500,600, 450};

//Temp 25:

unsigned int Temp_25[83] = {9050,4500, 450,600, 500,600, 450,600, 500,1700, 450,650, 450,650, 450,600, 500,600, 450,650, 450,1750, 450,600, 500,1700, 450,1700, 
                            500,600, 450,600, 500,650, 450,600, 500,600, 450,600, 500,1750, 450,600, 450,650, 450,600, 500,600, 500,600, 500,600, 450,600, 500,
                            600, 500,1700, 450,650, 450,600, 500,600, 450,650, 450,650, 450,1700, 500,1700, 450,600, 500,600, 450,650, 450,650, 450};





//Configuração da rede

const char* ssid     = "brisa-395282";
const char* password = "kfxhp9mq";


// Web Server na porta 80
WiFiServer server(80);

//Variável para armazenar a solicitação HTTP
String header;

//Definição de variaveis

//+
//+  Para adicionar mais botão (acionar um atuador) é só criar mais botões++
//+  Lembrar de adicionar no código HTML+
//+
//+

String botao1 = "off";
String botao2 = "off";

const int btn1 = 5;
const int btn2 = 4;

int temperatura = 0;
int umidade = 0;

//+
//+  A porta deve segui o mapa de pinos do ESP8266

//Definição de variaveis para o tempo

unsigned long hora = millis(); 
unsigned long hora_ant = 0;  
const    long total = 2000;

void setup(){
  
  Serial.begin(115200);
  
  //Inicializa as variaveis
  
  pinMode(btn1, OUTPUT);
  pinMode(btn2, OUTPUT);
  digitalWrite(btn1, LOW);
  digitalWrite(btn2, LOW);

  //Conexão com WiFi
  
  Serial.print("Conectando ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  //Mostra no Monitor Serial o IP reservado para o ESP8266
  //+
  //+  Pode-se definir um endereço padrão
  //+
  //+
  
  Serial.println("");
  Serial.println("Conexão realizado com sucesso ;)");
  Serial.println(ssid);
  Serial.println("Endereço IP: ");
  Serial.println(WiFi.localIP());
  server.begin();

}

void loop(){
  
  WiFiClient client = server.available();   //Aguardando cliente

  if (client){                             //Conectado com sucesso
    Serial.println("Novo cliente.");        
    
    String cliente = "";                // Pega os dados do cliente
    hora = millis();
    hora_ant = hora;
    
    while (client.connected() && hora - hora_ant <= total){ //Roda enquanto o cliente tiver conectado
     
      hora = millis();         
      
      if (client.available()){             
        
        char c = client.read();             
        Serial.write(c);
        header += c;
        
        if(c == '\n'){                    
          
          if(cliente.length() == 0){

            //Cabeçalho HTTP
            
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            //Pega os valores do sensor DHT11
  
            umidade = dht.readHumidity();
            temperatura = dht.readTemperature();
            
            if (header.indexOf("GET /5/on") >= 0) {
              
              Serial.println("Ligando Lampada");
              botao1 = "on";
              digitalWrite(btn1, HIGH);
           
            } else if (header.indexOf("GET /5/off") >= 0) {
              
              Serial.println("Desligando Lampada");
              botao1 = "off";
              digitalWrite(btn1, LOW);
            
            } 
            if(header.indexOf("GET /4/on") >= 0){

              Serial.println("Ligando Ar-Condicionado");
              botao2 = "on";
              digitalWrite(btn2, HIGH);
              emissorIR.sendRaw(Ligar, tam, frequencia);
                        
                           
            } else if(header.indexOf("GET /4/off") >= 0){

              Serial.println("Desligando Ar-Condicionado");
              botao2 = "off";
              emissorIR.sendRaw(Desligar, tam, frequencia);
              
            }

            if(header.indexOf("GET /4/16") >= 0){

              emissorIR.sendRaw(Temp_16, tam, frequencia);
              temp = 16;
            }
            else if(header.indexOf("GET /4/17") >= 0){

              emissorIR.sendRaw(Temp_17, tam, frequencia);
              temp = 17;
            }
            else if(header.indexOf("GET /4/18") >= 0){

              emissorIR.sendRaw(Temp_18, tam, frequencia);
              temp = 18;
            }
            else if(header.indexOf("GET /4/19") >= 0){

              emissorIR.sendRaw(Temp_19, tam, frequencia);
              temp = 19;
            }
            else if(header.indexOf("GET /4/20") >= 0){

              emissorIR.sendRaw(Temp_20, tam, frequencia);
              temp = 20;
            }
            else if(header.indexOf("GET /4/21") >= 0){

              emissorIR.sendRaw(Temp_21, tam, frequencia);
              temp = 21;
            }
            else if(header.indexOf("GET /4/22") >= 0){

              emissorIR.sendRaw(Temp_22, tam, frequencia);
              temp = 22;
            }
            else if(header.indexOf("GET /4/23") >= 0){

              emissorIR.sendRaw(Temp_23, tam, frequencia);
              temp = 23;
            }
            else if(header.indexOf("GET /4/24") >= 0){

              emissorIR.sendRaw(Temp_24, tam, frequencia);
              temp = 24;
            }
            else if(header.indexOf("GET /4/25") >= 0){

              emissorIR.sendRaw(Temp_25, tam, frequencia);
              temp = 25;
            }

          
            
            //Página HTML5/CSS
           
            client.println("<!DOCTYPE html> <html lang\"pt-br\">");
            client.println("<head><meta charset=\"UTF-8\" name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">");
            client.println("<meta http-equiv=\"refresh\" content=\"30\" >");
            client.println("<link href=\"https://fonts.googleapis.com/css?family=Open+Sans:300,400,600\" rel=\"stylesheet\">");
            client.println("<title>IOT-LAIS</title>");
            client.println("<style>html { font-family: 'Open Sans', sans-serif; display: block; margin: 0px auto; text-align: center;color: #333333;}");
            client.println("body{margin-top: 50px;}");
            client.println("h1 {margin: 50px auto 30px;}");
            client.println(".side-by-side{display: inline-block;vertical-align: middle;position: relative;}");
            client.println(".humidity-icon{background-color: #3498db;width: 30px;height: 30px;border-radius: 50%;line-height: 36px;}");
            client.println(".humidity-text{font-weight: 600;padding-left: 15px;font-size: 19px;width: 160px;text-align: left;}");
            client.println(".humidity{font-weight: 300;font-size: 25px;color: #3498db;}");
            client.println(".temperature-icon{background-color: #f39c12;width: 30px;height: 30px;border-radius: 50%;line-height: 40px;}");
            client.println(".temperature-text{font-weight: 600;padding-left: 15px;font-size: 19px;width: 160px;text-align: left;}");
            client.println(".temperature{font-weight: 300;font-size: 25px;color: #f39c12;}");
            client.println(".super{font-size: 17px;font-weight: 600;position: absolute;right: -20px;top: 4px;}");
            client.println(".data{padding: 10px;}");
            client.println(".btn-luzes, .btn-ar {width: 50%;height: 50px ;border: hidden;margin-bottom: 15px;border-radius: 20px;font-size: 16px;color: gainsboro; box-shadow: 2px 4px 2px darkgray;background-color: #800000;}");
            client.println(".btn-luzes2, .btn-ar2 {width: 50%;height: 50px ;border: hidden;margin-bottom: 15px;border-radius: 20px;font-size: 16px;color: gainsboro; box-shadow: 2px 4px 2px darkgray;background-color: #00FF00;}");
            client.println(".buttono {width: 60px;height: 30px ;border: hidden;margin-bottom: 15px;border-radius: 20px;font-size: 20px;box-shadow: 2px 4px 2px darkgray;color: #ffffff}");
            client.println(".temp{font-size: 20px;");
            client.println("</style>");
       
            client.println("</head>");
            client.println("<body>");
            client.println("<div id=\"webpage\">");
            client.println("<h1>Sala 1</h1>");
            client.println("<div class=\"data\">");
            client.println("<div >");
           
            if (botao1 == "off") {
              
              client.println("<p><a href=\"/5/on\"><button class=\"btn-luzes\">Lâmpada</button></a></p>");
            
            } else {
              
              client.println("<p><a href=\"/5/off\"><button class=\"button btn-luzes2\">Lâmpada</button></a></p>");
            } 

            //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
                              
            if (botao2 == "off") {
              
              client.println("<p><a href=\"/4/on\"><button class=\"btn-ar\">Ar-Condicionado</button></a></p>");
              
           
            } else {
             
              client.println("<p><a href=\"/4/off\"><button class=\"button btn-ar2\">Ar-Condicionado</button></a></p>");
            }


            //+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

            if(temp == 16){
              
                client.println("<p  class=\temp\"><a href=\"/4/17\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/16\"><button class=\"buttono\">-</button></a></p>");
            }
            if(temp == 17){
              
                client.println("<p><a href=\"/4/18\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/16\"><button class=\"buttono\">-</button></a></p>");
            }
            if(temp == 18){
              
                client.println("<p><a href=\"/4/19\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/17\"><button class=\"buttono\">-</button></a></p>");
            }
            if(temp == 19){
              
                client.println("<p><a href=\"/4/20\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/18\"><button class=\"buttono\">-</button></a></p>");
            }
            if(temp == 20){
              
                client.println("<p><a href=\"/4/21\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/19\"><button class=\"buttono\">-</button></a></p>");
            }
            if(temp == 21){
              
                client.println("<p><a href=\"/4/22\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/20\"><button class=\"buttono\">-</button></a></p>");
            }
            if(temp == 22){
              
                client.println("<p><a href=\"/4/23\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/21\"><button class=\"buttono\">-</button></a></p>");
            }
            if(temp == 23){
              
                client.println("<p><a href=\"/4/24\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/22\"><button class=\"buttono\">-</button></a></p>");
            }
             if(temp == 24){
              
                client.println("<p><a href=\"/4/25\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/23\"><button class=\"buttono\">-</button></a></p>");
            }
             if(temp == 25){
              
                client.println("<p><a href=\"/4/25\"><button class=\"buttono\">+</button></a>");
                client.println(temp);
                client.println("<a href=\"/4/24\"><button class=\"buttono\">-</button></a></p>");
            }

                        
            
            client.println("</div>");
            client.println("<div >");
            client.println("</div>");
            client.println("<div class=\"side-by-side temperature-icon\">");
            client.println("<svg version=\"1.1\" id=\"Layer_1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\"");
            client.println("<width=\"9.915px\" height=\"22px\" viewBox=\"0 0 9.915 22\" enable-background=\"new 0 0 9.915 22\" xml:space=\"preserve\">");
            client.println("<path fill=\"#FFFFFF\" d=\"M3.498,0.53c0.377-0.331,0.877-0.501,1.374-0.527C5.697-0.04,6.522,0.421,6.924,1.142");
            client.println("c0.237,0.399,0.315,0.871,0.311,1.33C7.229,5.856,7.245,9.24,7.227,12.625c1.019,0.539,1.855,1.424,2.301,2.491");
            client.println("c0.491,1.163,0.518,2.514,0.062,3.693c-0.414,1.102-1.24,2.038-2.276,2.594c-1.056,0.583-2.331,0.743-3.501,0.463");
            client.println("c-1.417-0.323-2.659-1.314-3.3-2.617C0.014,18.26-0.115,17.104,0.1,16.022c0.296-1.443,1.274-2.717,2.58-3.394");
            client.println("c0.013-3.44,0-6.881,0.007-10.322C2.674,1.634,2.974,0.955,3.498,0.53z\"");
            client.println("</svg>");
            client.println("</div>");
            client.println("<div class=\"side-by-side temperature-text\">Temperatura</div>");
            client.println("<div class=\"side-by-side temperature\">");
            client.println(temperatura);
            client.println("<span class=\"super\">°C</span></div>");
            client.println("</div>");
            client.println("<div class=\"data\">");
            client.println("<div class=\"side-by-side humidity-icon\">");
            client.println("<svg version=\"1.1\" id=\"Layer_1\" xmlns=\"http://www.w3.org/2000/svg\" xmlns:xlink=\"http://www.w3.org/1999/xlink\" x=\"0px\" y=\"0px\"");
            client.println("; width=\"12px\" height=\"17.955px\" viewBox=\"0 0 13 17.955\" enable-background=\"new 0 0 13 17.955\" xml:space=\"preserve\">");
            client.println("<path fill=\"#FFFFFF\" d=\"M1.819,6.217C3.139,4.064,6.5,0,6.5,0s3.363,4.064,4.681,6.217c1.793,2.926,2.133,5.05,1.571,7.057");
            client.println("c-0.438,1.574-2.264,4.681-6.252,4.681c-3.988,0-5.813-3.107-6.252-4.681C-0.313,11.267,0.026,9.143,1.819,6.217\"></path>");
            client.println("</svg>");
            client.println("</div>");
            client.println("<div class=\"side-by-side humidity-text\">Umidade</div>");
            client.println("<div class=\"side-by-side humidity\">");
            client.println(umidade);
            client.println("<span class=\"super\">%</span></div>");
            client.println("</div>");
            client.println("</div>");
            client.println("</body>");
            client.println("</html>");
            
            //ok
            client.println();
            
            break;
          } else { 
            
            cliente = "";
          }
          
        } else if (c != '\r') {  
         
          cliente += c;      
        }
      }
    }
    
    header = "";
    
    client.stop();
    Serial.println("Cliente Desconectado ):");
    Serial.println("");
  }
}
