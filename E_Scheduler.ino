
const unsigned char Scheduler_bitmap[] PROGMEM = {
  0x03, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xf0, 0x1f, 0xff, 0x3f, 0xf8, 0x3f, 0xf2, 0xdf, 0xfc,
  0x7f, 0xf5, 0xf3, 0xfe, 0x7f, 0xed, 0x2d, 0xfe, 0xff, 0xed, 0xdf, 0x3f, 0xff, 0xde, 0xd2, 0xdf,
  0xff, 0xd7, 0xdd, 0xff, 0xff, 0xb0, 0xed, 0x1f, 0xff, 0xbf, 0xfd, 0xcf, 0xff, 0x6f, 0x3e, 0xef,
  0xff, 0x57, 0xcf, 0xcf, 0xfe, 0xef, 0xf3, 0xcf, 0xfe, 0xfb, 0xfc, 0x8f, 0xfd, 0xbc, 0xff, 0x9f,
  0xfd, 0x5f, 0x3f, 0x1f, 0xfb, 0xbf, 0xcf, 0x3f, 0xfb, 0xef, 0xf3, 0x3f, 0xf7, 0xf3, 0xfe, 0x7f,
  0xf3, 0xfc, 0xfe, 0x7f, 0xf4, 0xff, 0x3c, 0xff, 0xf7, 0x3f, 0xcc, 0xff, 0xf9, 0xcf, 0xf9, 0xff,
  0xfe, 0x73, 0xf9, 0xff, 0xff, 0x9c, 0xf3, 0xff, 0x7f, 0xe7, 0x33, 0xfe, 0x7f, 0xf9, 0xc7, 0xfe,
  0x3f, 0xfe, 0x67, 0xfc, 0x1f, 0xff, 0x8f, 0xf8, 0x0f, 0xff, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xc0
};

class schoolClass {
  private:
    String className = "udha";
    String teacherName;
    String roomNum;
    String period;
    String time;
  public:
    schoolClass(String className, String teacherName, String roomNum, String period, String time)
      : className(className), teacherName(teacherName), roomNum(roomNum), period(period), time(time) {
      //member initializer list to initialize icon_bitmap
    }

    void disp(bool side) {
      if (side == false) {
        display.setFont(&FreeSerif24pt7b);
        display.setTextSize(1);
        display.setTextColor(BLACK);
        display.setCursor(4, 50);
        display.println(period);
      } else {
        display.fillRect(0, 0, 50, 68, BLACK);
        display.setFont(&FreeSerif24pt7b);
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(4, 50);
        display.println(period);
      }
      display.setTextColor(BLACK);
      display.setFont(&FreeSerif9pt7b);
      display.setCursor(50, 16);
      display.setTextSize(1);
      display.println(className);

      display.setCursor(50, 32);
      display.println(teacherName);
      display.setCursor(50, 58);
      display.setTextSize(1);
      display.setFont(&FreeSerif12pt7b);

      if (side == false)
        display.println(roomNum);
      else
        display.println(time);
      display.refresh();
    }
};
//setting up classes
schoolClass schedule[] = {
  schoolClass("Basic Wood", "Mr. Harman", "1410", "01", "7:20-8:10"),
  schoolClass("CP 12 ENG", "Mr. Burtch", "2413", "02", "8:11-9:00"),
  schoolClass("AP CALC BC", "Mr. Thesing", "1517", "03", "9:01-9:50"),
  schoolClass("Lunch", "NONE", "CAFE", "04", "9:51-10:25"),
  schoolClass("Person Finance", "Mrs.Lisa", "2320", "56", "10:26-11:15"),
  schoolClass("AP PHYS C", "Mrs. Whalen", "2419", "78", "11:16-12:05"),
  schoolClass("Study hall", "Mr. Lyberger", "1409", "91", "12:06-12:55"),
  schoolClass("AP GOV", "Mr. Shaw", "2522", "11", "12:56-1:45"),
  schoolClass("AP CS A", "Mrs. Williams", "1516", "12", "1:46-2:35")
};
bool side = false;
bool update = false;
int list = 1;
const int items = 9;
void scheduler() {
  ok.loop();
  up.loop();
  down.loop();
  if (millis() > sleeep + 10000){
    display.setFont();
  display.setTextSize(1);
  display.setTextColor(WHITE, BLACK);
  display.setCursor(0, 0);
  display.println("SLEEP");
  display.refresh();
  LowPower.sleep();
  }
  if (up.isReleased() == true && list != items)
    list += 1;
  if (down.isReleased() == true && list != 1)
    list -= 1;
  if (ok.isReleased()) {
    if (side == false)
      side = true;
    else if (side == true)
      side = false;
  }
  if (up.isReleased() || down.isReleased() || ok.isReleased()) {
    update = true;
  }

  if (update == true) {
    display.clearDisplayBuffer();
    schedule[list - 1].disp(side);
    update = false;
  }

}

//app Scheduler("Scheduler", "School schedule senior year", Scheduler_bitmap [], void (*appFunc)())
