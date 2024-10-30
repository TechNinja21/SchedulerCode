void setup() {
  if (lowPower == false) {  //starting usb communication if low power is false
    Serial.begin(9600);
  }
  else{
    //LowPower.attachInterruptWakeup(pin, okay, CHANGE);
  }
  //display setup
  //start & clear the display
  display.begin();
  display.clearDisplay();
  display.setTextWrap (false);
  //LED setup
  strip.begin();            //initialize pins for output
  strip.setBrightness(50);  //set brightness
  strip.clear();            //clear LED
  strip.show();             //turn all LED off ASAP

  //buttonSetup
  up.setDebounceTime(50);
  down.setDebounceTime(50);
  ok.setDebounceTime(50);

  delay(10000);  //DONT EVER REMOVE ME

  LowPower.attachInterruptWakeup(up_pin, intu, CHANGE);
  LowPower.attachInterruptWakeup(down_pin, intu, CHANGE);
  LowPower.attachInterruptWakeup(ok_pin, intu, CHANGE);
}
void intu() {
  sleeep=millis();
}
