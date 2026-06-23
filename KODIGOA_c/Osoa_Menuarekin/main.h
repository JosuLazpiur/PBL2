//DEFINE-AK
    //SENSOREAK
#define SENSOR_IZQ_PIN 4
#define SENSOR_DER_PIN 8

/*
ERRUBERAK : _F = FRONT  _B = BACK
            R_ = RIGHT  L_ = LEFT */

#define FL_F 25
#define FL_B 24
#define FR_F 27
#define FR_B 17
#define BL_F 5
#define BL_B 6
#define BR_F 22
#define BR_B 23

//FUNTZIO NAGUSIAK
int main_floyd();
int main_sigue_lineas();
int main_sigue_lineas_floyd();
int main_remoto(int argc, char* argv[]);

