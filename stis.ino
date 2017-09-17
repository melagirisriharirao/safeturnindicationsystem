//**********************************************************************************************************************//
//**********************************************************************************************************************//
//******************************************SAFE TURN INDICATION SYSTEM*************************************************//
//**********************************************************************************************************************//
//**********************************************************************************************************************//
int sensor1=9;    //sensor 1 is connected to pin 9
int sensor2=8;    //sensor 2 is connected to pin 8
int led1 =13;     //led1 is connected to pin 13
int led2 =12;     //led2 is connected to pin 12
int p=0;          // p and q variables are used to store the delay timings
int q=0;
int std_del=5000;

void setup() 
{
  pinMode(sensor1,INPUT_PULLUP);
  pinMode(sensor2,INPUT_PULLUP);
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
}

void loop()
{
 if((digitalRead(sensor1)==LOW) && (digitalRead(sensor2)==LOW))
    {
      ledon(0,0);
    }
 else if((digitalRead(sensor1)==LOW) && (digitalRead(sensor2)==HIGH))
    {
       ledon(0,1);
    }
 else if((digitalRead(sensor1)==HIGH) && (digitalRead(sensor2)==LOW))
    {
        ledon(1,0);
    }
 else
    {
       digitalWrite(led1,LOW);
       digitalWrite(led2,LOW);
    } 
}

void ledon(int a,int b)
{
  for(int i=0;i<std_del;i++)
      {
        switch((2*a)+b)
               {
                 case 3: if(i<(std_del-p))
                           {
                               digitalWrite(led1,HIGH);
                           }
                          if(i<(std_del-q))
                           {
                               digitalWrite(led2,HIGH);
                           }
                         delay(1);
                         p=(digitalRead(sensor1)==a)?0:i;
                         q=(digitalRead(sensor2)==b)?0:i;
                         if((digitalRead(sensor1)==LOW)||(digitalRead(sensor2)==LOW))
                             return;
                         break;
                 case 2:  if(i<(std_del-p))
                            {
                               digitalWrite(led1,HIGH);
                            }
                          if(i<(std_del-q))
                            {
                               digitalWrite(led2,LOW);
                            }
                          delay(1);
                          p=(digitalRead(sensor1)==a)?0:i;
                          q=(digitalRead(sensor2)==b)?0:i;
                          if((digitalRead(sensor1)==LOW)||(digitalRead(sensor2)==LOW))
                             return;
                          break;
                  case 1:  if(i<(std_del-p))
                              {
                                 digitalWrite(led1,LOW);
                              }
                           if(i<(std_del-q))
                              {
                                 digitalWrite(led2,HIGH);
                              }
                           delay(1);
                           p=(digitalRead(sensor1)==a)?0:i;
                           q=(digitalRead(sensor2)==b)?0:i;
                           if((digitalRead(sensor1)==LOW)||(digitalRead(sensor2)==LOW))
                                return;
                           break;

               }
  }
  p=0;
  q=0;
}




