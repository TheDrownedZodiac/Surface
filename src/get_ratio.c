/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-02 - 16:11 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: ratio
 */

float get_ratio(int a, int b, int x)
{
    float k;

    if (a == b) {
        return 1;
    }
    k = ((float) x - a) / ((float) b - a);
    return k;
}
