
int leds[]={6,9,11};
int i,i2;//Variable auxiliar para condicionales
 
void setup() {                
  pinMode(leds[0], OUTPUT);//Se inicializa como OUTPUT el pin a usar. Debe ser PWM
  pinMode(leds[1], OUTPUT);//Se inicializa como OUTPUT el pin a usar. Debe ser PWM
  pinMode(leds[2], OUTPUT);//Se inicializa como OUTPUT el pin a usar. Debe ser PWM
 
}
 
void loop() {
//Se recorren los valores desde el 0 al 255 para enviar una señal PWM con ciclo de trabajo de 0% a 100%
//aumentando en 2.55% el ciclo de trabajo cada 10 mili segundos.  
for(i2=0;i2<3;i2++){
        for(i=0; i<256; i++){ 
          analogWrite(leds[i2],i);
          delay(10);
        }
      //Se recorren los valores del 255 al 0 de mayor a menor igual que el for anterior.
        for(i=255; i>-1; i--){
          analogWrite(leds[i2],i);
          delay(10);
        }
    }
}
