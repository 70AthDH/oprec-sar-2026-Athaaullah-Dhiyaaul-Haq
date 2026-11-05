#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int cls;    // 0 = DUMMY, 1 = KORBAN, 2 = RERUNTUHAN, 3 = SAFEZONE
    float conf; // 0.0 .. 1.0
    long age_ms;// umur deteksi (ms sejak terlihat)
    float bearing;// derajat, + = kanan dari tengah kamera
    float dist;// mm, -1 = tidak tahu
} det_t;

bool mau_ambil(det_t d) {
    return (d.cls == 1) && (d.age_ms <= 1000) && (d.conf >= 0.5f);
}

int main() {
    det_t sample = {1, 0.5f, 120, 10.5f, 2.0f};
    
    if (mau_ambil(sample)) {
        printf("korban di amankan");
    } else {
        printf("korbant tidak bisa diselamatkan");
    }
    
    return 0;
}