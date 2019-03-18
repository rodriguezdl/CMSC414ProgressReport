#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

char payload[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Molestie a iaculis at erat pellentesque adipiscing commodo. Quis risus sed vulputate odio ut. Magnis dis parturient montes nascetur. Fermentum dui faucibus in ornare quam viverra orci. Orci phasellus egestas tellus rutrum tellus pellentesque. Malesuada bibendum arcu vitae elementum. In hac habitasse platea dictumst quisque sagittis. Diam maecenas sed enim ut sem viverra aliquet eget. Donec massa sapien faucibus et molestie ac. Id nibh tortor id aliquet. Diam phasellus vestibulum lorem sed risus ultricies tristique nulla aliquet. Integer malesuada nunc vel risus. Morbi tristique senectus et netus et malesuada fames. Facilisis volutpat est velit egestas. Eu feugiat pretium nibh ipsum consequat nisl vel pretium lectus. Elit sed vulputate mi sit amet. Velit euismod in pellentesque massa placerat duis. Viverra accumsan in nisl nisi scelerisque eu.";

size_t fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {
	size_t bytesToWrite = MAX(size * nmemb - 1, strlen(payload) - strlen(payload) % size);
	memcpy(ptr, payload, bytesToWrite);
	payload[bytesToWrite] = '\0';
	return bytesToWrite / size;
}

long int ftell(FILE *stream) {
	return strlen(payload);
}

