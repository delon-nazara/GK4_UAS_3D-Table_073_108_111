#include <glut.h>

// Fungsi untuk menginisialisasi pengaturan OpenGL
void initOpenGL() {
    glEnable(GL_DEPTH_TEST);  // Mengaktifkan pengujian kedalaman
    glEnable(GL_LIGHTING);     // Mengaktifkan pencahayaan
    glEnable(GL_LIGHT0);       // Mengaktifkan sumber cahaya pertama
    glEnable(GL_COLOR_MATERIAL); // Mengaktifkan material berwarna

    // Posisi dan properti cahaya
    GLfloat lightPos[] = { 5.0f, 5.0f, 5.0f, 1.0f };
    GLfloat lightAmbient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat lightDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat lightSpecular[] = { 1.0f, 1.0f, 1.0f, 1.0f };

    // Menyeting posisi dan properti cahaya
    glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
    glLightfv(GL_LIGHT0, GL_AMBIENT, lightAmbient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, lightDiffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, lightSpecular);

    glClearColor(0.5f, 0.8f, 1.0f, 1.0f); // Warna latar belakang biru langit
}

// Fungsi untuk menggambar karpet piknik dengan warna merah muda solid
void drawCarpet() {
    glDisable(GL_LIGHTING); // Menonaktifkan pencahayaan untuk karpet
    glColor3f(1.0f, 0.75f, 0.8f); // Warna merah muda
    glPushMatrix();
    glTranslatef(0.0f, -0.5f, 0.0f); // Memindahkan karpet sedikit ke bawah
    glScalef(5.0f, 0.1f, 5.0f);  // Menyesuaikan ukuran karpet
    glutSolidCube(1.0f);  // Menggambar kubus solid untuk karpet
    glPopMatrix();
    glEnable(GL_LIGHTING); // Mengaktifkan kembali pencahayaan untuk objek lainnya
}

// Fungsi untuk menggambar keranjang piknik (lebih pendek sedikit)
void drawBasket() {
    glColor3f(0.6f, 0.4f, 0.2f); // Warna coklat untuk keranjang

    // Basis keranjang (diperkecil dan diposisikan)
    glPushMatrix();
    glTranslatef(0.0f, 0.15f, 1.8f);  // Memindahkan keranjang agar tetap berada di atas karpet
    glScalef(2.0f, 0.8f, 1.2f);        // Mengurangi tinggi keranjang sedikit
    glutSolidCube(1.0f);  // Menggambar kubus solid untuk keranjang
    glPopMatrix();
}

// Fungsi untuk menggambar teko dan posisinya di ujung karpet
void drawTeapot() {
    glColor3f(0.2f, 0.6f, 0.8f); // Warna biru untuk teko
    glPushMatrix();
    glTranslatef(1.8f, 0.0f, 1.8f);  // Memposisikan teko di ujung karpet
    glutSolidTeapot(0.5);  // Menggambar teko dengan ukuran 0.5
    glPopMatrix();
}

// Fungsi untuk menggambar buah-buahan (dalam bentuk bola)
void drawFruits() {
    // Apel
    glColor3f(1.0f, 0.0f, 0.0f); // Warna merah untuk apel
    glPushMatrix();
    glTranslatef(-1.0f, 0.0f, -1.0f);  // Memposisikan apel sedikit lebih jauh
    glutSolidSphere(0.2, 20, 20); // Menggambar bola padat untuk apel
    glPopMatrix();

    // Jeruk
    glColor3f(1.0f, 0.5f, 0.0f); // Warna oranye untuk jeruk
    glPushMatrix();
    glTranslatef(1.0f, 0.0f, -1.0f);  // Memposisikan jeruk sedikit lebih jauh
    glutSolidSphere(0.2, 20, 20); // Menggambar bola padat untuk jeruk
    glPopMatrix();

    // Anggur (diwakili oleh sekumpulan bola)
    glColor3f(0.6f, 0.0f, 0.6f); // Warna ungu untuk anggur
    glPushMatrix();
    glTranslatef(0.0f, 0.0f, -1.0f);  // Posisi anggur sedikit lebih jauh

    // Membuat sekumpulan bola kecil untuk anggur
    for (float i = -0.1f; i <= 0.1f; i += 0.1f) {
        for (float j = -0.1f; j <= 0.1f; j += 0.1f) {
            glPushMatrix();
            glTranslatef(i, 0.2f, j);  // Menentukan posisi bola-bola kecil
            glutSolidSphere(0.1, 10, 10); // Menggambar bola kecil untuk anggur
            glPopMatrix();
        }
    }
    glPopMatrix();
}

// Fungsi callback untuk menampilkan objek di layar
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Membersihkan layar
    glLoadIdentity(); // Mengatur ulang matriks model-view
    gluLookAt(5.0, 5.0, 5.0,  // Posisi kamera
        0.0, 0.0, 0.0,  // Titik yang dilihat
        0.0, 1.0, 0.0); // Vektor atas kamera

    // Menggambar objek
    drawCarpet();
    drawBasket();  // Menggambar keranjang
    drawTeapot();  // Menggambar teko
    drawFruits();  // Menggambar buah-buahan (apel, jeruk, anggur)

    glutSwapBuffers();  // Menukar buffer untuk menampilkan gambar
}

// Fungsi callback untuk mengubah ukuran jendela
void reshape(int w, int h) {
    glViewport(0, 0, w, h);  // Mengubah area tampilan
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 100.0); // Menyeting perspektif
    glMatrixMode(GL_MODELVIEW);
}

// Fungsi utama untuk menjalankan program
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600); // Ukuran jendela
    glutCreateWindow("3D Picnic Scene");

    initOpenGL(); // Inisialisasi pengaturan OpenGL

    glutDisplayFunc(display); // Fungsi untuk menampilkan objek
    glutReshapeFunc(reshape); // Fungsi untuk mengubah ukuran jendela

    glutMainLoop();  // Memulai loop utama glut
    return 0;
}
