#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/videodev2.h>

void print_audioset(__u32 audioset)
{
	__u32 v, flag = 0;
	for(flag = 0; flag < 32; flag++)
	{
		v = 1 << flag;
		if(0 != (audioset & v))
		{
			printf("audio\t[%d]\n", flag);
		}
	}	
}

void print_input_type(__u32 type)
{
	switch(type)	
	{
		case V4L2_INPUT_TYPE_TUNER:
			printf("V4L2_INPUT_TYPE_TUNER");
			break;
		case V4L2_INPUT_TYPE_CAMERA:
			printf("V4L2_INPUT_TYPE_CAMERA");
			break;
		default:
			printf("V4L2_INPUT_TYPE_NONE");
			break;
	}
}

void print_input(struct v4l2_input *input) 
{
	printf("\n------v4l2_input------\n");
	printf("index\t[%x]\n", input->index);
	printf("name\t[%s]\n", input->name);
	printf("type\t[");
	print_input_type(input->type);
	printf("]\n");
	printf("tuner\t[%x]\n", input->tuner);
	printf("status\t[%x]\n", input->status);
	printf("capab\t[%x]\n", input->capabilities);
	print_audioset(input->audioset);
}

int main(int argc, char **argv)
{
	int fd, index;
	struct v4l2_input input;
	if(1 == argc){
		perror("input device path");
		exit(EXIT_FAILURE);
	}
	fd = open(argv[1], O_RDWR | O_NONBLOCK, 0);
	if (fd < 0) {
		perror("Cannot open device");
		exit(EXIT_FAILURE);
	}
	if(-1 == ioctl(fd, VIDIOC_G_INPUT, &index)){
		perror("VIDIOC_G_INPUT");
		exit(EXIT_FAILURE);
	}
	memset(&input, 0, sizeof(input));
	input.index = index;
	if(-1 == ioctl(fd, VIDIOC_ENUMINPUT, &input)){
		perror("VIDIOC_ENUMINPUT");
		exit(EXIT_FAILURE);
	}
	
	print_input(&input);

	close(fd);

	exit(0);
}
