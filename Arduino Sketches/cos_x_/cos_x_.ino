#define PI 3.14159

void setup()
{
  Serial.begin(9600);
}


void loop()
{
  int i,n;
  float x,sum,t;

  //Serial.print("give x in degree :\n ");
  x=analogRead(A0);
  x=map(x,0,1023,0,90);
  Serial.println("\nx = ");
  Serial.print(x);
  x=(PI*x)/180.0;

  //Serial.print("give number of terms n : ");
  n=analogRead(A1);
  n=map(n,0,1023,0,300);
  Serial.println("\nn =  ");
  Serial.print(n);
  sum=1.0;
  t=1.0;

  for(i=1;i<=(n-1);i++)
  {
    t=-t*x*x/((2*i-1)*2*i);
    sum+=t;
    
  }

  Serial.println("\ncos (x) =  ");
  Serial.print(sum);
  delay(400);
}


//////////////output
/*x = 
45.00
n =  
300
cos (x) =  
0.71*/
