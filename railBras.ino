int courant = 8;
int ground = 9;
int count = 0;
int pos = 0;
int i = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(courant,OUTPUT);
  pinMode(ground,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    String c = "";
    c = Serial.readStringUntil(10);
    count = c.toInt();
    i = (count-pos)/abs(pos-count);
    if(pos > count){
      ground = 8;
      courant = 9;
    }
    else if(pos < count){
      ground = 9;
      courant = 8;
    }
  }
  if(pos == count){
    digitalWrite(courant,LOW);
    digitalWrite(ground,LOW);
  }
  else{
    digitalWrite(courant,HIGH);
    digitalWrite(ground,LOW);
    pos += i;
  }

  Serial.println("pos :");
  Serial.println(pos);
  Serial.println("count :");
  Serial.println(count);

  delay(10);
}
