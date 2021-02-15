#include "safeLogger.hpp"

safeLogger::safeLogger(){
}

safeLogger::safeLogger(string a){
    file.open(a.c_str());
}

void safeLogger::log(string a, int level){
    safe.lock();
    time_t _tm =time(NULL );

    struct tm * curtime = localtime ( &_tm );
    switch(level){
    case 0:
        cout << asctime(curtime) << " [INFORMATION] " << a << endl;
        if(file.is_open()){
                file << asctime(curtime) << " [INFORMATION] " << a << endl;
        }
        break;
    case 1:
        cout << asctime(curtime) << " [WARNING] " << a << endl;
        if(file.is_open()){
            file << asctime(curtime) << " [WARNING] " << a << endl;
        }
        break;
    case 2:
        cout << asctime(curtime) << " [ERROR] " << a << endl;
        if(file.is_open()){
            file << asctime(curtime) << " [ERROR] " << a << endl;
        }
        break;
    default:
        cout << asctime(curtime) << " [DEBUG] " << a << endl;
        if(file.is_open()){
            file << asctime(curtime) << " [DEBUG] " << a << endl;
        }
        break;
    }
    safe.unlock();
}
