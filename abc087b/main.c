#include <stdio.h>

int main(void) {
    int a, b, c, x;
    scanf("%d%d%d%d", &a, &b, &c, &x);

    int ans = 0;
    for(int ax = 0 ; ax <= a ; ++ax) {
        for(int bx = 0 ; bx <= b ; ++bx) {
            for(int cx = 0 ; cx <= c ; ++cx) {
                int dst = ax * 500 + bx * 100 + cx * 50;
                if (dst == x) {
                    ans++;
                    //printf("[DEBUG] ans=%d, a=%d, b=%d, c=%d\n", ans, ax, bx, cx);
                    break;
                } else if(dst > x) {
                    break;
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}