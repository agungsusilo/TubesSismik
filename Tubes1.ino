# TubesSismik
tubes mata kuliah sistem mikroprosesor
//this is a list of long variables used in this clock program
long s = 0;
long sec = 0;
long hrs = 0;
long minutes = 0;
long initialHours = 17;//variable to initiate hours
long initialMins = 23;//variable to initiate minutes
long initialSecs = 01;//variable to initiate seconds

signed char jam_satuan, jam_puluhan, menit_satuan, menit_puluhan;

int segment[] ={2,3,4,5,6,7,8,13};     // pin a, b, c, d, e, f, g, dp
int seg_con[]  = {9,10,11,12};               // Selector 7-segment

//first loop variable
boolean start = true;

//this method is for seconds
long seconds()
{
  s = initialHours * 3600;
  s = s + (initialMins * 60);
  s = s + initialSecs;
  s = s + (millis() / 1000);
  return s;
}

//this method is for hours
long hours()
{
  hrs = seconds();
  hrs = hrs / 3600;
  hrs = hrs % 24;
  return hrs;
}

//this method is for minutes
long mins()
{
  minutes = seconds();
  minutes = minutes / 60;
  minutes = minutes % 60;
  return minutes;
}

long secs()
{
  sec = seconds();
  sec = sec % 60;
  return sec;
}

void setup() {
  // initialize the digital pins as outputs.
  pinMode(segment[0], OUTPUT);
  pinMode(segment[1], OUTPUT);
  pinMode(segment[2], OUTPUT);
  pinMode(segment[3], OUTPUT);
  pinMode(segment[4], OUTPUT);
  pinMode(segment[5], OUTPUT);
  pinMode(segment[6], OUTPUT);
  pinMode(seg_con[0], OUTPUT);
  pinMode(seg_con[1], OUTPUT);
  pinMode(seg_con[2], OUTPUT);
  pinMode(seg_con[3], OUTPUT);
  Serial.begin(9600);
}

void loop() {

  hours();
  mins();
  secs();

  jam_satuan = hrs % 10;
  jam_puluhan = hrs / 10;
  menit_satuan = minutes % 10;
  menit_puluhan = minutes / 10;

  show(jam_puluhan, jam_satuan, menit_puluhan, menit_satuan); 

}
//------------------------------//

// menampilkan jam digital
void show(signed char a, signed char b, signed char c, signed char d)
{
    digitalWrite(seg_con[3],LOW);  // Digit Keempat
    digitalWrite(seg_con[2],HIGH);
    digitalWrite(seg_con[1],HIGH);
    digitalWrite(seg_con[0],HIGH);
    tampil_7(d);
    delay(5);
    
    digitalWrite(seg_con[3],HIGH);
    digitalWrite(seg_con[2],LOW);  // Digit Ketiga
    digitalWrite(seg_con[1],HIGH);
    digitalWrite(seg_con[0],HIGH);
    tampil_7(c);
    delay(5);
   
    digitalWrite(seg_con[3],HIGH);   // Digit Kedua
    digitalWrite(seg_con[2],HIGH);
    digitalWrite(seg_con[1],LOW);
    digitalWrite(seg_con[0],HIGH);
    tampil_7(b);
    delay(5);
    
    digitalWrite(seg_con[3],HIGH);   // Digit Pertama
    digitalWrite(seg_con[2],HIGH);
    digitalWrite(seg_con[1],HIGH);
    digitalWrite(seg_con[0],LOW);
    tampil_7(a);
    delay(5);
}

// Menampilakn angka pada 7-segment
void tampil_7(int nilai) 
{
  if (nilai==0){
            digitalWrite(segment[0], HIGH);
            digitalWrite(segment[1], HIGH);
            digitalWrite(segment[2], HIGH);
            digitalWrite(segment[3], HIGH);
            digitalWrite(segment[4], HIGH);      
            digitalWrite(segment[5], HIGH);
            digitalWrite(segment[6], LOW);
            digitalWrite(segment[7], LOW);
  }
  else if (nilai==1) {
            digitalWrite(segment[0], LOW);
            digitalWrite(segment[1], HIGH);
            digitalWrite(segment[2], HIGH);
            digitalWrite(segment[3], LOW);
            digitalWrite(segment[4], LOW);
            digitalWrite(segment[5], LOW);
            digitalWrite(segment[6], LOW);
            digitalWrite(segment[7], LOW);   
  }
  else if (nilai==2){
            digitalWrite(segment[0], HIGH);
            digitalWrite(segment[1], HIGH);
            digitalWrite(segment[2], LOW);
            digitalWrite(segment[3], HIGH);
            digitalWrite(segment[4], HIGH);
            digitalWrite(segment[5], LOW);
            digitalWrite(segment[6], HIGH);
            digitalWrite(segment[7], LOW);
  }
  else if (nilai==3)  {
          digitalWrite(segment[0], HIGH);
          digitalWrite(segment[1], HIGH);
          digitalWrite(segment[2], HIGH);
          digitalWrite(segment[3], HIGH);
          digitalWrite(segment[4], LOW);
          digitalWrite(segment[5], LOW);
          digitalWrite(segment[6], HIGH);
          digitalWrite(segment[7], LOW);
  }
  else if (nilai==4){
            digitalWrite(segment[0], LOW);
            digitalWrite(segment[1], HIGH);
            digitalWrite(segment[2], HIGH);
            digitalWrite(segment[3], LOW);
            digitalWrite(segment[4], LOW);
            digitalWrite(segment[5], HIGH);
            digitalWrite(segment[6], HIGH);
            digitalWrite(segment[7], LOW);
  }
  else if (nilai==5){
            digitalWrite(segment[0], HIGH);
            digitalWrite(segment[1], LOW);
            digitalWrite(segment[2], HIGH);
            digitalWrite(segment[3], HIGH);
            digitalWrite(segment[4], LOW);
            digitalWrite(segment[5], HIGH);
            digitalWrite(segment[6], HIGH);
            digitalWrite(segment[7], LOW);
  }
  else if (nilai==6){
            digitalWrite(segment[0], HIGH);
            digitalWrite(segment[1], LOW);
            digitalWrite(segment[2], HIGH);
            digitalWrite(segment[3], HIGH);
            digitalWrite(segment[4], HIGH);
            digitalWrite(segment[5], HIGH);
            digitalWrite(segment[6], HIGH);
            digitalWrite(segment[7], LOW);
  }
  else if (nilai==7){
            digitalWrite(segment[0], HIGH);
            digitalWrite(segment[1], HIGH);
            digitalWrite(segment[2], HIGH);
            digitalWrite(segment[3], LOW);
            digitalWrite(segment[4], LOW);
            digitalWrite(segment[5], LOW);
            digitalWrite(segment[6], LOW);
            digitalWrite(segment[7], LOW);
  }
  else if (nilai==8){
            digitalWrite(segment[0], HIGH);
            digitalWrite(segment[1], HIGH);
            digitalWrite(segment[2], HIGH);
            digitalWrite(segment[3], HIGH);
            digitalWrite(segment[4], HIGH);
            digitalWrite(segment[5], HIGH);
            digitalWrite(segment[6], HIGH);
            digitalWrite(segment[7], LOW);
  }
  else if (nilai==9)
  {
            digitalWrite(segment[0], HIGH);
            digitalWrite(segment[1], HIGH);
            digitalWrite(segment[2], HIGH);
            digitalWrite(segment[3], HIGH);
            digitalWrite(segment[4], LOW);
            digitalWrite(segment[5], HIGH);
            digitalWrite(segment[6], HIGH);
            digitalWrite(segment[7], LOW);
  }
  else if (nilai==10)
  {
            digitalWrite(segment[0], LOW);
            digitalWrite(segment[1], LOW);
            digitalWrite(segment[2], LOW);
            digitalWrite(segment[3], LOW);
            digitalWrite(segment[4], LOW);
            digitalWrite(segment[5], LOW);
            digitalWrite(segment[6], HIGH);
            digitalWrite(segment[7], LOW);
  }
}
