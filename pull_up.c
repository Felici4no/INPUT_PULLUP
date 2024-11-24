// Define constantes para facilitar a identificação dos pinos usados
#define LED_VERMELHO 4      // Pino conectado ao LED vermelho
#define BOTAO_VERMELHO 10   // Pino conectado ao botão vermelho
#define LED_VERDE           // (Incompleto, parece que este define não foi usado ou está ausente)

// Configuração inicial do programa
void setup() {
  Serial.begin(9600); // Inicia a comunicação serial para enviar mensagens ao computador
  
  pinMode(LED_VERMELHO, OUTPUT); // Configura o pino do LED vermelho como saída
  pinMode(BOTAO_VERMELHO, INPUT_PULLUP); // Configura o pino do botão como entrada com resistor pull-up interno
  
  // Faz o LED vermelho piscar rapidamente no início (indicativo de inicialização)
  digitalWrite(LED_VERMELHO, HIGH); // Liga o LED vermelho
  delay(1000);                      // Aguarda 1 segundo
  digitalWrite(LED_VERMELHO, LOW);  // Desliga o LED vermelho
}

// Laço principal do programa
void loop() {
  // Lê o estado do botão (1 para não pressionado, 0 para pressionado)
  int estadoBotao = digitalRead(BOTAO_VERMELHO); 
  
  // Envia o estado do botão ao monitor serial
  Serial.println(estadoBotao); 
  delay(500); // Aguarda meio segundo para evitar leituras repetidas
  
  // Controla o LED com base no estado do botão
  if (estadoBotao == 0) { // Se o botão estiver pressionado (LOW devido ao pull-up)
    digitalWrite(LED_VERMELHO, HIGH); // Liga o LED vermelho
  } else { // Se o botão estiver solto
    digitalWrite(LED_VERMELHO, LOW); // Desliga o LED vermelho
  }
}
