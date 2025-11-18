#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

#define length 3
#define face 6
char* colors[face] = {
	"white","red","blue","green","orange","yellow"
};
char letters[face] = {
	'w','r','b','g','o','y'
};
int hexcolors[face] = {
	0xFFF, 0xF00, 0x00F, 0x0F0, 0xFA0, 0xFF0
}