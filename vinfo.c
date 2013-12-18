#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/videodev2.h>

void print_cap_flags(__u64 cap)
{
	if(V4L2_CAP_VIDEO_CAPTURE == (V4L2_CAP_VIDEO_CAPTURE & cap))
		printf("V4L2_CAP_VIDEO_CAPTURE\n");
	if(V4L2_CAP_VIDEO_CAPTURE_MPLANE == (V4L2_CAP_VIDEO_CAPTURE_MPLANE & cap))
		printf("V4L2_CAP_VIDEO_CAPTURE_MPLANE\n");
	if(V4L2_CAP_VIDEO_OUTPUT == (V4L2_CAP_VIDEO_OUTPUT & cap))
		printf("V4L2_CAP_VIDEO_OUTPUT\n");
	if(V4L2_CAP_VIDEO_OUTPUT_MPLANE == (V4L2_CAP_VIDEO_OUTPUT_MPLANE & cap))
		printf("V4L2_CAP_VIDEO_OUTPUT_MPLANE\n");
	/*if(V4L2_CAP_VIDEO_M2M == (V4L2_CAP_VIDEO_M2M & cap))
		printf("V4L2_CAP_VIDEO_M2M\n");
	if(V4L2_CAP_VIDEO_M2M_MPLANE == (V4L2_CAP_VIDEO_M2M_MPLANE & cap))
		printf("V4L2_CAP_VIDEO_M2M_MPLANE\n");*/
	if(V4L2_CAP_VIDEO_OVERLAY == (V4L2_CAP_VIDEO_OVERLAY & cap))
		printf("V4L2_CAP_VIDEO_OVERLAY\n");
	if(V4L2_CAP_VBI_CAPTURE == (V4L2_CAP_VBI_CAPTURE & cap))
		printf("V4L2_CAP_VBI_CAPTURE\n");
	if(V4L2_CAP_VBI_OUTPUT == (V4L2_CAP_VBI_OUTPUT & cap))
		printf("V4L2_CAP_VBI_OUTPUT\n");
	if(V4L2_CAP_SLICED_VBI_CAPTURE == (V4L2_CAP_SLICED_VBI_CAPTURE & cap))
		printf("V4L2_CAP_SLICED_VBI_CAPTURE\n");
	if(V4L2_CAP_SLICED_VBI_OUTPUT == (V4L2_CAP_SLICED_VBI_OUTPUT & cap))
		printf("V4L2_CAP_SLICED_VBI_OUTPUT\n");
	if(V4L2_CAP_RDS_CAPTURE == (V4L2_CAP_RDS_CAPTURE & cap))
		printf("V4L2_CAP_RDS_CAPTURE\n");
	if(V4L2_CAP_VIDEO_OUTPUT_OVERLAY == (V4L2_CAP_VIDEO_OUTPUT_OVERLAY & cap))
		printf("V4L2_CAP_VIDEO_OUTPUT_OVERLAY\n");
	if(V4L2_CAP_HW_FREQ_SEEK == (V4L2_CAP_HW_FREQ_SEEK & cap))
		printf("V4L2_CAP_HW_FREQ_SEEK\n");
	if(V4L2_CAP_RDS_OUTPUT == (V4L2_CAP_RDS_OUTPUT & cap))
		printf("V4L2_CAP_RDS_OUTPUT\n");
	if(V4L2_CAP_TUNER == (V4L2_CAP_TUNER & cap))
		printf("V4L2_CAP_TUNER\n");
	if(V4L2_CAP_AUDIO == (V4L2_CAP_AUDIO & cap))
		printf("V4L2_CAP_AUDIO\n");
	if(V4L2_CAP_RADIO == (V4L2_CAP_RADIO & cap))
		printf("V4L2_CAP_RADIO\n");
	if(V4L2_CAP_MODULATOR == (V4L2_CAP_MODULATOR & cap))
		printf("V4L2_CAP_MODULATOR\n");
	if(V4L2_CAP_READWRITE == (V4L2_CAP_READWRITE & cap))
		printf("V4L2_CAP_READWRITE\n");
	if(V4L2_CAP_ASYNCIO == (V4L2_CAP_ASYNCIO & cap))
		printf("V4L2_CAP_ASYNCIO\n");
	if(V4L2_CAP_STREAMING == (V4L2_CAP_STREAMING & cap))
		printf("V4L2_CAP_STREAMING\n");
	/*if(V4L2_CAP_DEVICE_CAPS == (V4L2_CAP_DEVICE_CAPS & cap))
		printf("V4L2_CAP_DEVICE_CAPS\n");*/
}

void print_v4l2_std_id(__u64 std)
{
	if(V4L2_STD_PAL_B == (V4L2_STD_PAL_B & std))
		printf("V4L2_STD_PAL_B\n");
	if(V4L2_STD_PAL_B1 == (V4L2_STD_PAL_B1 & std))
		printf("V4L2_STD_PAL_B1\n");
	if(V4L2_STD_PAL_G == (V4L2_STD_PAL_G & std))
		printf("V4L2_STD_PAL_G\n");
	if(V4L2_STD_PAL_H == (V4L2_STD_PAL_H & std))
		printf("V4L2_STD_PAL_H\n");
	if(V4L2_STD_PAL_I == (V4L2_STD_PAL_I & std))
		printf("V4L2_STD_PAL_I\n");
	if(V4L2_STD_PAL_D == (V4L2_STD_PAL_D & std))
		printf("V4L2_STD_PAL_D\n");
	if(V4L2_STD_PAL_D1 == (V4L2_STD_PAL_D1 & std))
		printf("V4L2_STD_PAL_D1\n");
	if(V4L2_STD_PAL_K == (V4L2_STD_PAL_K & std))
		printf("V4L2_STD_PAL_K\n");
	if(V4L2_STD_PAL_M == (V4L2_STD_PAL_M & std))
		printf("V4L2_STD_PAL_M\n");
	if(V4L2_STD_PAL_N == (V4L2_STD_PAL_N & std))
		printf("V4L2_STD_PAL_N\n");
	if(V4L2_STD_PAL_Nc == (V4L2_STD_PAL_Nc & std))
		printf("V4L2_STD_PAL_Nc\n");
	if(V4L2_STD_PAL_60 == (V4L2_STD_PAL_60 & std))
		printf("V4L2_STD_PAL_60\n");
	if(V4L2_STD_NTSC_M == (V4L2_STD_NTSC_M & std))
		printf("V4L2_STD_NTSC_M\n");
	if(V4L2_STD_NTSC_M_JP == (V4L2_STD_NTSC_M_JP & std))
		printf("V4L2_STD_NTSC_M_JP\n");
	if(V4L2_STD_NTSC_443 == (V4L2_STD_NTSC_443 & std))
		printf("V4L2_STD_NTSC_443\n");
	if(V4L2_STD_NTSC_M_KR == (V4L2_STD_NTSC_M_KR & std))
		printf("V4L2_STD_NTSC_M_KR\n");
	if(V4L2_STD_SECAM_B == (V4L2_STD_SECAM_B & std))
		printf("V4L2_STD_SECAM_B\n");
	if(V4L2_STD_SECAM_D == (V4L2_STD_SECAM_D & std))
		printf("V4L2_STD_SECAM_D\n");
	if(V4L2_STD_SECAM_G == (V4L2_STD_SECAM_G & std))
		printf("V4L2_STD_SECAM_G\n");
	if(V4L2_STD_SECAM_H == (V4L2_STD_SECAM_H & std))
		printf("V4L2_STD_SECAM_H\n");
	if(V4L2_STD_SECAM_K == (V4L2_STD_SECAM_K & std))
		printf("V4L2_STD_SECAM_K\n");
	if(V4L2_STD_SECAM_K1 == (V4L2_STD_SECAM_K1 & std))
		printf("V4L2_STD_SECAM_K1\n");
	if(V4L2_STD_SECAM_L == (V4L2_STD_SECAM_L & std))
		printf("V4L2_STD_SECAM_L\n");
	if(V4L2_STD_SECAM_LC == (V4L2_STD_SECAM_LC & std))
		printf("V4L2_STD_SECAM_LC\n");
	if(V4L2_STD_ATSC_8_VSB == (V4L2_STD_ATSC_8_VSB & std))
		printf("V4L2_STD_ATSC_8_VSB\n");
	if(V4L2_STD_ATSC_16_VSB == (V4L2_STD_ATSC_16_VSB & std))
		printf("V4L2_STD_ATSC_16_VSB\n");
}

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

void print_cap(struct v4l2_capability * cap)
{
	printf("\n------v4l2_capability------\n");
	printf("dirver\t[%s]\n", cap->driver);
	printf("card\t[%s]\n", cap->card);
	printf("bus_i\t[%s]\n", cap->bus_info);
	printf("version\t[%x]\n", cap->version);
	printf("capab\t[%x]\n", cap->capabilities);
	print_cap_flags(cap->capabilities);
}

int main(int argc, char **argv)
{
	int fd, index;
	struct v4l2_input input;
	struct v4l2_output output;
	struct v4l2_capability cap;

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
	if(-1 == ioctl(fd, VIDIOC_QUERYCAP, &cap)){
		perror("VIDIOC_ENUMINPUT");
		exit(EXIT_FAILURE);
	}
	print_cap(&cap);

	close(fd);

	exit(0);
}
