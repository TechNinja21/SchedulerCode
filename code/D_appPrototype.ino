class app {
private:
  bool exit = false;
  String name="";
  String info="";
  const unsigned char* icon_bitmap;
  void (*appFunc)(); 
public:
  app(String name, String info, const unsigned char icon_bitmap[] PROGMEM, void (*appFunc)())
    : name(name), info(info), icon_bitmap(icon_bitmap), appFunc(appFunc) { 
    //member initializer list to initialize icon_bitmap
  }

  String getName(){
    return name;
  }

  String getInfo(){
    return info;
  }

  const unsigned char* getIcon() const {  //return a pointer to the icon bitmap array
    return icon_bitmap;
  }

  void start() {
    exit=false;
    while (exit != true) {
      appFunc();
    }
  }
  
  void stop() {
    exit = true;
  }

};
