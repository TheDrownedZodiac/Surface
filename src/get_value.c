/*
 * E89 Pedagogical & Technical Lab
 * project:     surface
 * created on:  2022-11-08 - 11:03 +0100
 * 1st author:  victor.vandeputte - victor.vandeputte
 * description: value
 */

int get_value(int a, int b, float ratio)
{
    int k;

    k = ratio * ((float) b - a) + (float) a;
    return k;
}
