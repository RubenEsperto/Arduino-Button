/*
Programador....: (c) Rúben Esperto
Data...........: 17/12/2024
*/
const byte BOTAO = 4;
const byte LED_VERMELHO = 12;

byte estadoBotao;
byte ultimoEstadoBotao = LOW;
unsigned long tempoUltimoDeBounce = 0;
unsigned long tempoDeBounce = 50;

void setup(void){
  pinMode(BOTAO, INPUT);
  pinMode(LED_VERMELHO, OUTPUT);
}

void loop(void){
    lerEstadoBotao();

    if (estadoBotao == HIGH) {
      digitalWrite(LED_VERMELHO, HIGH);
     }
      else {
      digitalWrite(LED_VERMELHO, LOW);
    }
}
void lerEstadoBotao()    {
  int leitura = digitalRead(BOTAO);

  if (leitura != ultimoEstadoBotao)    {
    tempoUltimoDeBounce = millis();
  }

  if((millis() - tempoUltimoDeBounce) > tempoDeBounce)    {
    if(leitura != estadoBotao)    {
      estadoBotao = leitura;
    }
  }

  ultimoEstadoBotao = leitura;
}
