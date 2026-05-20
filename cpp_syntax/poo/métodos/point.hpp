class Point {
private:
    int x = 0;
    int y = 0;

public:
    void moveTo(int px, int py);
    void translate(int dx, int dy);
    int getx();
    int gety();
    void setx(int val);
    void sety(int val);
};
