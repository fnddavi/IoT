/*
 * Autor: Rui Santos 
 * Complete Project Details http://randomnerdtutorials.com
 * 
 * Modificado e Adaptado por: Rodrigo Costa
 * Rev1: 21/03/2017
 * 
 * Maiores detalhes do Projeto em: 
 * https://eletronicaparatodos.com/
 * http://eletronicaparatodos.net/
 * 
 */

 /* 
  * Abaixo declaramos as variáveis que utilizaremos em nosso código
  * visando identificar os componentes eletronicos que vao no circuito.
  * ---------------------------------------------------------------------------
  * Dica do RCosta: observe que as variáveis são utilizadas como sendo
  * o verdadeiro nome do componente! Isso facilita a vida na hora da leitura :)
  * ---------------------------------------------------------------------------
  * 
  */
 
int carroVermelho = 13; 
int carroAmarelo = 12; 
int carroVerde = 11; 
int pessoaVerde = 2;
int pessoaVermelho = 3; 
int botao = 7;
int tempoAtravessando = 5000;
unsigned long mudaTempo;

void setup() {
  
  // Inicializamos o temporizador aqui
  // Observe que o "contador" foi atrelado
  // a váriavel que setamos acima.
  
  mudaTempo = millis();
  
  /* 
   *  Aqui nós configuramos alguns dos pinos da nossa placa Arduino como "saídas" e outros comos "entradas".
   *  Dica do RCosta: Isso significa que alguns pinos "mostrarão" o resultado enquanto outro 
   *  atuará como um sensor, "captando informações" do mundo exterior.
   *  OBS: Alguns perguntarão: por que utilizar "OUTPUT" e "INPUT" ao invés de utilizarmos "SAIDA" e "ENTRADA" respectivamente?
   *  Pessoal, a resposta é que não podemos fazer isso neste caso, isso porque a "memória interna" do Arduino só conhece estes
   *  comandos em idioma Inglês apenas, assim como outras situações que perceberão ao longo dos estudos, não desanima! :)
   *  
   */
  
  pinMode(carroVermelho, OUTPUT);
  pinMode(carroAmarelo, OUTPUT);
  pinMode(carroVerde, OUTPUT);
  pinMode(pessoaVermelho, OUTPUT);
  pinMode(pessoaVerde, OUTPUT);
  pinMode(botao, INPUT);
  
  //Começamos deixando acesas as luzes: verde (referente aos veículos) e vermelha (referente aos pedestres)
  //OBS: O comando "Serial.begin" utilizado abaixo serve neste caso como uma espécie de "DEBUG", isto porque
  //com este comando somos capazes de "acompanhar" o funcionamento do circuito pelo Painel Serial da IDE do Arduino!
  
  digitalWrite(carroVerde, HIGH);
  digitalWrite(pessoaVermelho, HIGH);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(carroAmarelo, LOW);
  digitalWrite(pessoaVerde, LOW);
  Serial.begin(9600);
}

void loop() {
  
  // A variável que vamos setar abaixo servirá para "guardar" o estado do nosso botão (pressionado ou não pressionado)
  
  int estado = digitalRead(botao);
  delay(50);
  Serial.println(estado);
  
  // Se o botão está sendo pressionado E se já passou 5 segundos desde a última pressão.
  
  if (estado == HIGH && (millis() - mudaTempo) > 5000) {
    
    //Então SE SIM, executa a função de mudar o estado das luzes abaixo:
    mudaLuzes();
  }
}

void mudaLuzes() {
  digitalWrite(carroVerde, LOW);    // A luz verde é desligada
  digitalWrite(carroAmarelo, HIGH); // A luz amarela vai ligar por 4 segundos
  delay(4000); 
  
  digitalWrite(carroAmarelo, LOW); // A luz amarela vai desligar
  digitalWrite(carroVermelho, HIGH); // A luz vermelha vai ligar por 5 segundos

  digitalWrite(pessoaVermelho, LOW);
  digitalWrite(pessoaVerde, HIGH);
  delay(tempoAtravessando);
  
  // Pisca a luz verde dos PEDESTRES
  for (int x=0; x<10; x++) {
    digitalWrite(pessoaVerde, LOW);
    delay(160);
    digitalWrite(pessoaVerde, HIGH);
    delay(160);
  }
  digitalWrite(pessoaVerde, LOW);
  digitalWrite(carroVermelho, LOW);
  digitalWrite(pessoaVermelho, HIGH);
  digitalWrite(carroVerde, HIGH);

  mudaTempo = millis();
 }
 