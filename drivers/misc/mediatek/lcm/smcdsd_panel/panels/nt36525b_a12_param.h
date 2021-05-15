/* SPDX-License-Identifier: GPL-2.0 */
#ifndef __NT36525B_PARAM_H__
#define __NT36525B_PARAM_H__

#include <linux/types.h>
#include <linux/kernel.h>

#define EXTEND_BRIGHTNESS	306
#define UI_MAX_BRIGHTNESS	255
#define UI_DEFAULT_BRIGHTNESS	128

#define LDI_REG_BRIGHTNESS	0x51
#define LDI_REG_ID		0xDA
#define LDI_LEN_BRIGHTNESS	((u16)ARRAY_SIZE(SEQ_NT36525B_BRIGHTNESS))

/* len is read length */
#define LDI_LEN_ID		3

#define TYPE_WRITE		I2C_SMBUS_WRITE
#define TYPE_DELAY		U8_MAX

static u8 LM36274_INIT[] = {
	TYPE_WRITE, 0x0C, 0x2C,
	TYPE_WRITE, 0x0D, 0x26,
	TYPE_WRITE, 0x0E, 0x26,
	TYPE_WRITE, 0x09, 0xBE,
	TYPE_WRITE, 0x02, 0x6B,
	TYPE_WRITE, 0x03, 0x0D,
	TYPE_WRITE, 0x11, 0x74,
	TYPE_WRITE, 0x04, 0x05,
	TYPE_WRITE, 0x05, 0xCC,
	TYPE_WRITE, 0x10, 0x67,
	TYPE_WRITE, 0x08, 0x13,
};

static u8 LM36274_EXIT[] = {
	TYPE_WRITE, 0x09, 0x18,
	TYPE_DELAY, 1, 0,
	TYPE_WRITE, 0x08, 0x00,
};

struct lcd_seq_info {
	unsigned char	*cmd;
	unsigned int	len;
	unsigned int	sleep;
};

static unsigned char SEQ_NT36525B_SLEEP_OUT[] = { 0x11 };
static unsigned char SEQ_NT36525B_SLEEP_IN[] = { 0x10 };
static unsigned char SEQ_NT36525B_DISPLAY_OFF[] = { 0x28 };
static unsigned char SEQ_NT36525B_DISPLAY_ON[] = { 0x29 };

static unsigned char SEQ_NT36525B_BRIGHTNESS[] = {
	0x51,
	0x00,
};

static unsigned char SEQ_NT36525B_001[] = {
	0xFF,
	0x20,
};

static unsigned char SEQ_NT36525B_002[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_003[] = {
	0x00,
	0x01,
};

static unsigned char SEQ_NT36525B_004[] = {
	0x01,
	0x55,
};

static unsigned char SEQ_NT36525B_005[] = {
	0x03,
	0x55,
};

static unsigned char SEQ_NT36525B_006[] = {
	0x05,
	0xA9,
};

static unsigned char SEQ_NT36525B_007[] = {
	0x07,
	0x73,
};

static unsigned char SEQ_NT36525B_008[] = {
	0x08,
	0xC1,
};

static unsigned char SEQ_NT36525B_009[] = {
	0x0E,
	0x91,
};

static unsigned char SEQ_NT36525B_010[] = {
	0x0F,
	0x5F,
};

static unsigned char SEQ_NT36525B_011[] = {
	0x1F,
	0x00,
};

static unsigned char SEQ_NT36525B_012[] = {
	0x69,
	0xA9,
};

static unsigned char SEQ_NT36525B_013[] = {
	0x94,
	0x00,
};

static unsigned char SEQ_NT36525B_014[] = {
	0x95,
	0xEB,
};

static unsigned char SEQ_NT36525B_015[] = {
	0x96,
	0xEB,
};

static unsigned char SEQ_NT36525B_016[] = {
	0xFF,
	0x24,
};

static unsigned char SEQ_NT36525B_017[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_018[] = {
	0x00,
	0x1E,
};

static unsigned char SEQ_NT36525B_019[] = {
	0x04,
	0x21,
};

static unsigned char SEQ_NT36525B_020[] = {
	0x06,
	0x22,
};

static unsigned char SEQ_NT36525B_021[] = {
	0x07,
	0x20,
};

static unsigned char SEQ_NT36525B_022[] = {
	0x08,
	0x1D,
};

static unsigned char SEQ_NT36525B_023[] = {
	0x0A,
	0x0C,
};

static unsigned char SEQ_NT36525B_024[] = {
	0x0B,
	0x0D,
};

static unsigned char SEQ_NT36525B_025[] = {
	0x0C,
	0x0E,
};

static unsigned char SEQ_NT36525B_026[] = {
	0x0D,
	0x0F,
};

static unsigned char SEQ_NT36525B_027[] = {
	0x0F,
	0x04,
};

static unsigned char SEQ_NT36525B_028[] = {
	0x10,
	0x05,
};

static unsigned char SEQ_NT36525B_029[] = {
	0x12,
	0x1E,
};

static unsigned char SEQ_NT36525B_030[] = {
	0x13,
	0x1E,
};

static unsigned char SEQ_NT36525B_031[] = {
	0x14,
	0x1E,
};

static unsigned char SEQ_NT36525B_032[] = {
	0x16,
	0x1E,
};

static unsigned char SEQ_NT36525B_033[] = {
	0x1A,
	0x21,
};

static unsigned char SEQ_NT36525B_034[] = {
	0x1C,
	0x22,
};

static unsigned char SEQ_NT36525B_035[] = {
	0x1D,
	0x20,
};

static unsigned char SEQ_NT36525B_036[] = {
	0x1E,
	0x1D,
};

static unsigned char SEQ_NT36525B_037[] = {
	0x20,
	0x0C,
};

static unsigned char SEQ_NT36525B_038[] = {
	0x21,
	0x0D,
};

static unsigned char SEQ_NT36525B_039[] = {
	0x22,
	0x0E,
};

static unsigned char SEQ_NT36525B_040[] = {
	0x23,
	0x0F,
};

static unsigned char SEQ_NT36525B_041[] = {
	0x25,
	0x04,
};

static unsigned char SEQ_NT36525B_042[] = {
	0x26,
	0x05,
};

static unsigned char SEQ_NT36525B_043[] = {
	0x28,
	0x1E,
};

static unsigned char SEQ_NT36525B_044[] = {
	0x29,
	0x1E,
};

static unsigned char SEQ_NT36525B_045[] = {
	0x2A,
	0x1E,
};

static unsigned char SEQ_NT36525B_046[] = {
	0x2F,
	0x0C,
};

static unsigned char SEQ_NT36525B_047[] = {
	0x30,
	0x0A,
};

static unsigned char SEQ_NT36525B_048[] = {
	0x33,
	0x0A,
};

static unsigned char SEQ_NT36525B_049[] = {
	0x34,
	0x0C,
};

static unsigned char SEQ_NT36525B_050[] = {
	0x37,
	0x66,
};

static unsigned char SEQ_NT36525B_051[] = {
	0x39,
	0x00,
};

static unsigned char SEQ_NT36525B_052[] = {
	0x3A,
	0x10,
};

static unsigned char SEQ_NT36525B_053[] = {
	0x3B,
	0x90,
};

static unsigned char SEQ_NT36525B_054[] = {
	0x3D,
	0x92,
};

static unsigned char SEQ_NT36525B_055[] = {
	0x4D,
	0x12,
};

static unsigned char SEQ_NT36525B_056[] = {
	0x4E,
	0x34,
};

static unsigned char SEQ_NT36525B_057[] = {
	0x51,
	0x43,
};

static unsigned char SEQ_NT36525B_058[] = {
	0x52,
	0x21,
};

static unsigned char SEQ_NT36525B_059[] = {
	0x55,
	0x87,
};

static unsigned char SEQ_NT36525B_060[] = {
	0x56,
	0x44,
};

static unsigned char SEQ_NT36525B_061[] = {
	0x5A,
	0x9F,
};

static unsigned char SEQ_NT36525B_062[] = {
	0x5B,
	0x90,
};

static unsigned char SEQ_NT36525B_063[] = {
	0x5C,
	0x00,
};

static unsigned char SEQ_NT36525B_064[] = {
	0x5D,
	0x00,
};

static unsigned char SEQ_NT36525B_065[] = {
	0x5E,
	0x04,
};

static unsigned char SEQ_NT36525B_066[] = {
	0x5F,
	0x00,
};

static unsigned char SEQ_NT36525B_067[] = {
	0x60,
	0x80,
};

static unsigned char SEQ_NT36525B_068[] = {
	0x61,
	0x90,
};

static unsigned char SEQ_NT36525B_069[] = {
	0x64,
	0x11,
};

static unsigned char SEQ_NT36525B_070[] = {
	0x82,
	0x0D,
};

static unsigned char SEQ_NT36525B_071[] = {
	0x83,
	0x05,
};

static unsigned char SEQ_NT36525B_072[] = {
	0x85,
	0x00,
};

static unsigned char SEQ_NT36525B_073[] = {
	0x86,
	0x51,
};

static unsigned char SEQ_NT36525B_074[] = {
	0x92,
	0xAD,
};

static unsigned char SEQ_NT36525B_075[] = {
	0x93,
	0x08,
};

static unsigned char SEQ_NT36525B_076[] = {
	0x94,
	0x0E,
};

static unsigned char SEQ_NT36525B_077[] = {
	0xAB,
	0x00,
};

static unsigned char SEQ_NT36525B_078[] = {
	0xAC,
	0x00,
};

static unsigned char SEQ_NT36525B_079[] = {
	0xAD,
	0x00,
};

static unsigned char SEQ_NT36525B_080[] = {
	0xAF,
	0x04,
};

static unsigned char SEQ_NT36525B_081[] = {
	0xB0,
	0x05,
};

static unsigned char SEQ_NT36525B_082[] = {
	0xB1,
	0xA8,
};

static unsigned char SEQ_NT36525B_083[] = {
	0xC2,
	0x86,
};

static unsigned char SEQ_NT36525B_084[] = {
	0xFF,
	0x25,
};

static unsigned char SEQ_NT36525B_085[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_086[] = {
	0x0A,
	0x82,
};

static unsigned char SEQ_NT36525B_087[] = {
	0x0B,
	0x26,
};

static unsigned char SEQ_NT36525B_088[] = {
	0x0C,
	0x01,
};

static unsigned char SEQ_NT36525B_089[] = {
	0x17,
	0x82,
};

static unsigned char SEQ_NT36525B_090[] = {
	0x18,
	0x06,
};

static unsigned char SEQ_NT36525B_091[] = {
	0x19,
	0x0F,
};

static unsigned char SEQ_NT36525B_092[] = {
	0x58,
	0x00,
};

static unsigned char SEQ_NT36525B_093[] = {
	0x59,
	0x00,
};

static unsigned char SEQ_NT36525B_094[] = {
	0x5A,
	0x40,
};

static unsigned char SEQ_NT36525B_095[] = {
	0x5B,
	0x80,
};

static unsigned char SEQ_NT36525B_096[] = {
	0x5C,
	0x00,
};

static unsigned char SEQ_NT36525B_097[] = {
	0x5D,
	0x9F,
};

static unsigned char SEQ_NT36525B_098[] = {
	0x5E,
	0x90,
};

static unsigned char SEQ_NT36525B_099[] = {
	0x5F,
	0x9F,
};

static unsigned char SEQ_NT36525B_100[] = {
	0x60,
	0x90,
};

static unsigned char SEQ_NT36525B_101[] = {
	0x61,
	0x9F,
};

static unsigned char SEQ_NT36525B_102[] = {
	0x62,
	0x90,
};

static unsigned char SEQ_NT36525B_103[] = {
	0x65,
	0x05,
};

static unsigned char SEQ_NT36525B_104[] = {
	0x66,
	0xA8,
};

static unsigned char SEQ_NT36525B_105[] = {
	0xC0,
	0x03,
};

static unsigned char SEQ_NT36525B_106[] = {
	0xCA,
	0x1C,
};

static unsigned char SEQ_NT36525B_107[] = {
	0xCC,
	0x1C,
};

static unsigned char SEQ_NT36525B_108[] = {
	0xD3,
	0x11,
};

static unsigned char SEQ_NT36525B_109[] = {
	0xD4,
	0xC8,
};

static unsigned char SEQ_NT36525B_110[] = {
	0xD5,
	0x11,
};

static unsigned char SEQ_NT36525B_111[] = {
	0xD6,
	0x1C,
};

static unsigned char SEQ_NT36525B_112[] = {
	0xD7,
	0x11,
};

static unsigned char SEQ_NT36525B_113[] = {
	0xFF,
	0x26,
};

static unsigned char SEQ_NT36525B_114[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_115[] = {
	0x00,
	0xA0,
};

static unsigned char SEQ_NT36525B_116[] = {
	0xFF,
	0x27,
};

static unsigned char SEQ_NT36525B_117[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_118[] = {
	0x13,
	0x00,
};

static unsigned char SEQ_NT36525B_119[] = {
	0x15,
	0xB4,
};

static unsigned char SEQ_NT36525B_120[] = {
	0x1F,
	0x55,
};

static unsigned char SEQ_NT36525B_121[] = {
	0x26,
	0x0F,
};

static unsigned char SEQ_NT36525B_122[] = {
	0xC0,
	0x18,
};

static unsigned char SEQ_NT36525B_123[] = {
	0xC1,
	0xF0,
};

static unsigned char SEQ_NT36525B_124[] = {
	0xC2,
	0x00,
};

static unsigned char SEQ_NT36525B_125[] = {
	0xC3,
	0x00,
};

static unsigned char SEQ_NT36525B_126[] = {
	0xC4,
	0xF0,
};

static unsigned char SEQ_NT36525B_127[] = {
	0xC5,
	0x00,
};

static unsigned char SEQ_NT36525B_128[] = {
	0xC6,
	0x00,
};

static unsigned char SEQ_NT36525B_129[] = {
	0xC7,
	0x03,
};

static unsigned char SEQ_NT36525B_130[] = {
	0xFF,
	0x23,
};

static unsigned char SEQ_NT36525B_131[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_132[] = {
	0x00,
	0x00,
};

static unsigned char SEQ_NT36525B_133[] = {
	0x04,
	0x00,
};

static unsigned char SEQ_NT36525B_134[] = {
	0x07,
	0x20,
};

static unsigned char SEQ_NT36525B_135[] = {
	0x08,
	0x0F,
};

static unsigned char SEQ_NT36525B_136[] = {
	0x09,
	0x00,
};

static unsigned char SEQ_NT36525B_137[] = {
	0x12,
	0xB4,
};

static unsigned char SEQ_NT36525B_138[] = {
	0x15,
	0xE9,
};

static unsigned char SEQ_NT36525B_139[] = {
	0x16,
	0x0B,
};

static unsigned char SEQ_NT36525B_140[] = {
	0x19,
	0x00,
};

static unsigned char SEQ_NT36525B_141[] = {
	0x1A,
	0x00,
};

static unsigned char SEQ_NT36525B_142[] = {
	0x1B,
	0x08,
};

static unsigned char SEQ_NT36525B_143[] = {
	0x1C,
	0x0A,
};

static unsigned char SEQ_NT36525B_144[] = {
	0x1D,
	0x0C,
};

static unsigned char SEQ_NT36525B_145[] = {
	0x1E,
	0x12,
};

static unsigned char SEQ_NT36525B_146[] = {
	0x1F,
	0x16,
};

static unsigned char SEQ_NT36525B_147[] = {
	0x20,
	0x1A,
};

static unsigned char SEQ_NT36525B_148[] = {
	0x21,
	0x1C,
};

static unsigned char SEQ_NT36525B_149[] = {
	0x22,
	0x20,
};

static unsigned char SEQ_NT36525B_150[] = {
	0x23,
	0x24,
};

static unsigned char SEQ_NT36525B_151[] = {
	0x24,
	0x28,
};

static unsigned char SEQ_NT36525B_152[] = {
	0x25,
	0x2C,
};

static unsigned char SEQ_NT36525B_153[] = {
	0x26,
	0x30,
};

static unsigned char SEQ_NT36525B_154[] = {
	0x27,
	0x38,
};

static unsigned char SEQ_NT36525B_155[] = {
	0x28,
	0x3C,
};

static unsigned char SEQ_NT36525B_156[] = {
	0x29,
	0x10,
};

static unsigned char SEQ_NT36525B_157[] = {
	0x30,
	0xFF,
};

static unsigned char SEQ_NT36525B_158[] = {
	0x31,
	0xFF,
};

static unsigned char SEQ_NT36525B_159[] = {
	0x32,
	0xFE,
};

static unsigned char SEQ_NT36525B_160[] = {
	0x33,
	0xFD,
};

static unsigned char SEQ_NT36525B_161[] = {
	0x34,
	0xFD,
};

static unsigned char SEQ_NT36525B_162[] = {
	0x35,
	0xFC,
};

static unsigned char SEQ_NT36525B_163[] = {
	0x36,
	0xFB,
};

static unsigned char SEQ_NT36525B_164[] = {
	0x37,
	0xF9,
};

static unsigned char SEQ_NT36525B_165[] = {
	0x38,
	0xF7,
};

static unsigned char SEQ_NT36525B_166[] = {
	0x39,
	0xF3,
};

static unsigned char SEQ_NT36525B_167[] = {
	0x3A,
	0xEA,
};

static unsigned char SEQ_NT36525B_168[] = {
	0x3B,
	0xE6,
};

static unsigned char SEQ_NT36525B_169[] = {
	0x3D,
	0xE0,
};

static unsigned char SEQ_NT36525B_170[] = {
	0x3F,
	0xDD,
};

static unsigned char SEQ_NT36525B_171[] = {
	0x40,
	0xDB,
};

static unsigned char SEQ_NT36525B_172[] = {
	0x41,
	0xD9,
};

static unsigned char SEQ_NT36525B_173[] = {
	0xFF,
	0x20,
};

static unsigned char SEQ_NT36525B_174[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_175[] = {
	0xB0,
	0x00, 0x08, 0x00, 0x18, 0x00, 0x33, 0x00, 0x4B, 0x00, 0x5F,
	0x00, 0x72, 0x00, 0x83, 0x00, 0x94,
};

static unsigned char SEQ_NT36525B_176[] = {
	0xB1,
	0x00, 0xA2, 0x00, 0xD7, 0x00, 0xFF, 0x01, 0x41, 0x01, 0x6F,
	0x01, 0xBD, 0x01, 0xF8, 0x01, 0xFA,
};

static unsigned char SEQ_NT36525B_177[] = {
	0xB2,
	0x02, 0x36, 0x02, 0x71, 0x02, 0x9C, 0x02, 0xD0, 0x02, 0xF5,
	0x03, 0x20, 0x03, 0x30, 0x03, 0x3E,
};

static unsigned char SEQ_NT36525B_178[] = {
	0xB3,
	0x03, 0x4F, 0x03, 0x63, 0x03, 0x7B, 0x03, 0x95, 0x03, 0xA6,
	0x03, 0xA7,
};

static unsigned char SEQ_NT36525B_179[] = {
	0xB4,
	0x00, 0x08, 0x00, 0x18, 0x00, 0x33, 0x00, 0x4B, 0x00, 0x5F,
	0x00, 0x72, 0x00, 0x83, 0x00, 0x94,
};

static unsigned char SEQ_NT36525B_180[] = {
	0xB5,
	0x00, 0xA2, 0x00, 0xD7, 0x00, 0xFF, 0x01, 0x41, 0x01, 0x6F,
	0x01, 0xBD, 0x01, 0xF8, 0x01, 0xFA,
};

static unsigned char SEQ_NT36525B_181[] = {
	0xB6,
	0x02, 0x36, 0x02, 0x71, 0x02, 0x9C, 0x02, 0xD0, 0x02, 0xF5,
	0x03, 0x20, 0x03, 0x30, 0x03, 0x3E,
};

static unsigned char SEQ_NT36525B_182[] = {
	0xB7,
	0x03, 0x4F, 0x03, 0x63, 0x03, 0x7B, 0x03, 0x95, 0x03, 0xA6,
	0x03, 0xA7,
};

static unsigned char SEQ_NT36525B_183[] = {
	0xB8,
	0x00, 0x08, 0x00, 0x18, 0x00, 0x33, 0x00, 0x4B, 0x00, 0x5F,
	0x00, 0x72, 0x00, 0x83, 0x00, 0x94,
};

static unsigned char SEQ_NT36525B_184[] = {
	0xB9,
	0x00, 0xA2, 0x00, 0xD7, 0x00, 0xFF, 0x01, 0x41, 0x01, 0x6F,
	0x01, 0xBD, 0x01, 0xF8, 0x01, 0xFA,
};

static unsigned char SEQ_NT36525B_185[] = {
	0xBA,
	0x02, 0x36, 0x02, 0x71, 0x02, 0x9C, 0x02, 0xD0, 0x02, 0xF5,
	0x03, 0x20, 0x03, 0x30, 0x03, 0x3E,
};

static unsigned char SEQ_NT36525B_186[] = {
	0xBB,
	0x03, 0x4F, 0x03, 0x63, 0x03, 0x7B, 0x03, 0x95, 0x03, 0xA6,
	0x03, 0xA7,
};

static unsigned char SEQ_NT36525B_187[] = {
	0xFF,
	0x21,
};

static unsigned char SEQ_NT36525B_188[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_189[] = {
	0xB0,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x2B, 0x00, 0x43, 0x00, 0x57,
	0x00, 0x6A, 0x00, 0x7B, 0x00, 0x8C,
};

static unsigned char SEQ_NT36525B_190[] = {
	0xB1,
	0x00, 0x9A, 0x00, 0xCF, 0x00, 0xF7, 0x01, 0x39, 0x01, 0x67,
	0x01, 0xB5, 0x01, 0xF0, 0x01, 0xF2,
};

static unsigned char SEQ_NT36525B_191[] = {
	0xB2,
	0x02, 0x2E, 0x02, 0x7B, 0x02, 0xAE, 0x02, 0xEA, 0x03, 0x13,
	0x03, 0x42, 0x03, 0x52, 0x03, 0x62,
};

static unsigned char SEQ_NT36525B_192[] = {
	0xB3,
	0x03, 0x73, 0x03, 0x89, 0x03, 0xA1, 0x03, 0xBD, 0x03, 0xCE,
	0x03, 0xD9,
};

static unsigned char SEQ_NT36525B_193[] = {
	0xB4,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x2B, 0x00, 0x43, 0x00, 0x57,
	0x00, 0x6A, 0x00, 0x7B, 0x00, 0x8C,
};

static unsigned char SEQ_NT36525B_194[] = {
	0xB5,
	0x00, 0x9A, 0x00, 0xCF, 0x00, 0xF7, 0x01, 0x39, 0x01, 0x67,
	0x01, 0xB5, 0x01, 0xF0, 0x01, 0xF2,
};

static unsigned char SEQ_NT36525B_195[] = {
	0xB6,
	0x02, 0x2E, 0x02, 0x7B, 0x02, 0xAE, 0x02, 0xEA, 0x03, 0x13,
	0x03, 0x42, 0x03, 0x52, 0x03, 0x62,
};

static unsigned char SEQ_NT36525B_196[] = {
	0xB7,
	0x03, 0x73, 0x03, 0x89, 0x03, 0xA1, 0x03, 0xBD, 0x03, 0xCE,
	0x03, 0xD9,
};

static unsigned char SEQ_NT36525B_197[] = {
	0xB8,
	0x00, 0x00, 0x00, 0x10, 0x00, 0x2B, 0x00, 0x43, 0x00, 0x57,
	0x00, 0x6A, 0x00, 0x7B, 0x00, 0x8C,
};

static unsigned char SEQ_NT36525B_198[] = {
	0xB9,
	0x00, 0x9A, 0x00, 0xCF, 0x00, 0xF7, 0x01, 0x39, 0x01, 0x67,
	0x01, 0xB5, 0x01, 0xF0, 0x01, 0xF2,
};

static unsigned char SEQ_NT36525B_199[] = {
	0xBA,
	0x02, 0x2E, 0x02, 0x7B, 0x02, 0xAE, 0x02, 0xEA, 0x03, 0x13,
	0x03, 0x42, 0x03, 0x52, 0x03, 0x62,
};

static unsigned char SEQ_NT36525B_200[] = {
	0xBB,
	0x03, 0x73, 0x03, 0x89, 0x03, 0xA1, 0x03, 0xBD, 0x03, 0xCE,
	0x03, 0xD9,
};

static unsigned char SEQ_NT36525B_201[] = {
	0xFF,
	0x24,
};

static unsigned char SEQ_NT36525B_202[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_203[] = {
	0x92,
	0xA9,
};

static unsigned char SEQ_NT36525B_204[] = {
	0xB1,
	0xA4,
};

static unsigned char SEQ_NT36525B_205[] = {
	0xFF,
	0x25,
};

static unsigned char SEQ_NT36525B_206[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_207[] = {
	0x0B,
	0x19,
};

static unsigned char SEQ_NT36525B_208[] = {
	0x66,
	0xA4,
};

static unsigned char SEQ_NT36525B_209[] = {
	0xFF,
	0xE0,
};

static unsigned char SEQ_NT36525B_210[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_211[] = {
	0x25,
	0x11,
};

static unsigned char SEQ_NT36525B_212[] = {
	0x4E,
	0x01,
};

static unsigned char SEQ_NT36525B_213[] = {
	0xFF,
	0x10,
};

static unsigned char SEQ_NT36525B_214[] = {
	0xFB,
	0x01,
};

static unsigned char SEQ_NT36525B_215[] = {
	0xBA,
	0x02,
};

static unsigned char SEQ_NT36525B_216[] = {
	0x51,
	0x00,
};

static unsigned char SEQ_NT36525B_217[] = {
	0x53,
	0x2C,
};

static unsigned char SEQ_NT36525B_218[] = {
	0x55,
	0x01,
};

static unsigned char SEQ_NT36525B_219[] = {
	0x68,
	0x00, 0x01,
};

static struct lcd_seq_info LCD_SEQ_INIT_1[] = {
	{SEQ_NT36525B_001, ARRAY_SIZE(SEQ_NT36525B_001), 0, },
	{SEQ_NT36525B_002, ARRAY_SIZE(SEQ_NT36525B_002), 0, },
	{SEQ_NT36525B_003, ARRAY_SIZE(SEQ_NT36525B_003), 0, },
	{SEQ_NT36525B_004, ARRAY_SIZE(SEQ_NT36525B_004), 0, },
	{SEQ_NT36525B_005, ARRAY_SIZE(SEQ_NT36525B_005), 0, },
	{SEQ_NT36525B_006, ARRAY_SIZE(SEQ_NT36525B_006), 0, },
	{SEQ_NT36525B_007, ARRAY_SIZE(SEQ_NT36525B_007), 0, },
	{SEQ_NT36525B_008, ARRAY_SIZE(SEQ_NT36525B_008), 0, },
	{SEQ_NT36525B_009, ARRAY_SIZE(SEQ_NT36525B_009), 0, },
	{SEQ_NT36525B_010, ARRAY_SIZE(SEQ_NT36525B_010), 0, },
	{SEQ_NT36525B_011, ARRAY_SIZE(SEQ_NT36525B_011), 0, },
	{SEQ_NT36525B_012, ARRAY_SIZE(SEQ_NT36525B_012), 0, },
	{SEQ_NT36525B_013, ARRAY_SIZE(SEQ_NT36525B_013), 0, },
	{SEQ_NT36525B_014, ARRAY_SIZE(SEQ_NT36525B_014), 0, },
	{SEQ_NT36525B_015, ARRAY_SIZE(SEQ_NT36525B_015), 0, },
	{SEQ_NT36525B_016, ARRAY_SIZE(SEQ_NT36525B_016), 0, },
	{SEQ_NT36525B_017, ARRAY_SIZE(SEQ_NT36525B_017), 0, },
	{SEQ_NT36525B_018, ARRAY_SIZE(SEQ_NT36525B_018), 0, },
	{SEQ_NT36525B_019, ARRAY_SIZE(SEQ_NT36525B_019), 0, },
	{SEQ_NT36525B_020, ARRAY_SIZE(SEQ_NT36525B_020), 0, },
	{SEQ_NT36525B_021, ARRAY_SIZE(SEQ_NT36525B_021), 0, },
	{SEQ_NT36525B_022, ARRAY_SIZE(SEQ_NT36525B_022), 0, },
	{SEQ_NT36525B_023, ARRAY_SIZE(SEQ_NT36525B_023), 0, },
	{SEQ_NT36525B_024, ARRAY_SIZE(SEQ_NT36525B_024), 0, },
	{SEQ_NT36525B_025, ARRAY_SIZE(SEQ_NT36525B_025), 0, },
	{SEQ_NT36525B_026, ARRAY_SIZE(SEQ_NT36525B_026), 0, },
	{SEQ_NT36525B_027, ARRAY_SIZE(SEQ_NT36525B_027), 0, },
	{SEQ_NT36525B_028, ARRAY_SIZE(SEQ_NT36525B_028), 0, },
	{SEQ_NT36525B_029, ARRAY_SIZE(SEQ_NT36525B_029), 0, },
	{SEQ_NT36525B_030, ARRAY_SIZE(SEQ_NT36525B_030), 0, },
	{SEQ_NT36525B_031, ARRAY_SIZE(SEQ_NT36525B_031), 0, },
	{SEQ_NT36525B_032, ARRAY_SIZE(SEQ_NT36525B_032), 0, },
	{SEQ_NT36525B_033, ARRAY_SIZE(SEQ_NT36525B_033), 0, },
	{SEQ_NT36525B_034, ARRAY_SIZE(SEQ_NT36525B_034), 0, },
	{SEQ_NT36525B_035, ARRAY_SIZE(SEQ_NT36525B_035), 0, },
	{SEQ_NT36525B_036, ARRAY_SIZE(SEQ_NT36525B_036), 0, },
	{SEQ_NT36525B_037, ARRAY_SIZE(SEQ_NT36525B_037), 0, },
	{SEQ_NT36525B_038, ARRAY_SIZE(SEQ_NT36525B_038), 0, },
	{SEQ_NT36525B_039, ARRAY_SIZE(SEQ_NT36525B_039), 0, },
	{SEQ_NT36525B_040, ARRAY_SIZE(SEQ_NT36525B_040), 0, },
	{SEQ_NT36525B_041, ARRAY_SIZE(SEQ_NT36525B_041), 0, },
	{SEQ_NT36525B_042, ARRAY_SIZE(SEQ_NT36525B_042), 0, },
	{SEQ_NT36525B_043, ARRAY_SIZE(SEQ_NT36525B_043), 0, },
	{SEQ_NT36525B_044, ARRAY_SIZE(SEQ_NT36525B_044), 0, },
	{SEQ_NT36525B_045, ARRAY_SIZE(SEQ_NT36525B_045), 0, },
	{SEQ_NT36525B_046, ARRAY_SIZE(SEQ_NT36525B_046), 0, },
	{SEQ_NT36525B_047, ARRAY_SIZE(SEQ_NT36525B_047), 0, },
	{SEQ_NT36525B_048, ARRAY_SIZE(SEQ_NT36525B_048), 0, },
	{SEQ_NT36525B_049, ARRAY_SIZE(SEQ_NT36525B_049), 0, },
	{SEQ_NT36525B_050, ARRAY_SIZE(SEQ_NT36525B_050), 0, },
	{SEQ_NT36525B_051, ARRAY_SIZE(SEQ_NT36525B_051), 0, },
	{SEQ_NT36525B_052, ARRAY_SIZE(SEQ_NT36525B_052), 0, },
	{SEQ_NT36525B_053, ARRAY_SIZE(SEQ_NT36525B_053), 0, },
	{SEQ_NT36525B_054, ARRAY_SIZE(SEQ_NT36525B_054), 0, },
	{SEQ_NT36525B_055, ARRAY_SIZE(SEQ_NT36525B_055), 0, },
	{SEQ_NT36525B_056, ARRAY_SIZE(SEQ_NT36525B_056), 0, },
	{SEQ_NT36525B_057, ARRAY_SIZE(SEQ_NT36525B_057), 0, },
	{SEQ_NT36525B_058, ARRAY_SIZE(SEQ_NT36525B_058), 0, },
	{SEQ_NT36525B_059, ARRAY_SIZE(SEQ_NT36525B_059), 0, },
	{SEQ_NT36525B_060, ARRAY_SIZE(SEQ_NT36525B_060), 0, },
	{SEQ_NT36525B_061, ARRAY_SIZE(SEQ_NT36525B_061), 0, },
	{SEQ_NT36525B_062, ARRAY_SIZE(SEQ_NT36525B_062), 0, },
	{SEQ_NT36525B_063, ARRAY_SIZE(SEQ_NT36525B_063), 0, },
	{SEQ_NT36525B_064, ARRAY_SIZE(SEQ_NT36525B_064), 0, },
	{SEQ_NT36525B_065, ARRAY_SIZE(SEQ_NT36525B_065), 0, },
	{SEQ_NT36525B_066, ARRAY_SIZE(SEQ_NT36525B_066), 0, },
	{SEQ_NT36525B_067, ARRAY_SIZE(SEQ_NT36525B_067), 0, },
	{SEQ_NT36525B_068, ARRAY_SIZE(SEQ_NT36525B_068), 0, },
	{SEQ_NT36525B_069, ARRAY_SIZE(SEQ_NT36525B_069), 0, },
	{SEQ_NT36525B_070, ARRAY_SIZE(SEQ_NT36525B_070), 0, },
	{SEQ_NT36525B_071, ARRAY_SIZE(SEQ_NT36525B_071), 0, },
	{SEQ_NT36525B_072, ARRAY_SIZE(SEQ_NT36525B_072), 0, },
	{SEQ_NT36525B_073, ARRAY_SIZE(SEQ_NT36525B_073), 0, },
	{SEQ_NT36525B_074, ARRAY_SIZE(SEQ_NT36525B_074), 0, },
	{SEQ_NT36525B_075, ARRAY_SIZE(SEQ_NT36525B_075), 0, },
	{SEQ_NT36525B_076, ARRAY_SIZE(SEQ_NT36525B_076), 0, },
	{SEQ_NT36525B_077, ARRAY_SIZE(SEQ_NT36525B_077), 0, },
	{SEQ_NT36525B_078, ARRAY_SIZE(SEQ_NT36525B_078), 0, },
	{SEQ_NT36525B_079, ARRAY_SIZE(SEQ_NT36525B_079), 0, },
	{SEQ_NT36525B_080, ARRAY_SIZE(SEQ_NT36525B_080), 0, },
	{SEQ_NT36525B_081, ARRAY_SIZE(SEQ_NT36525B_081), 0, },
	{SEQ_NT36525B_082, ARRAY_SIZE(SEQ_NT36525B_082), 0, },
	{SEQ_NT36525B_083, ARRAY_SIZE(SEQ_NT36525B_083), 0, },
	{SEQ_NT36525B_084, ARRAY_SIZE(SEQ_NT36525B_084), 0, },
	{SEQ_NT36525B_085, ARRAY_SIZE(SEQ_NT36525B_085), 0, },
	{SEQ_NT36525B_086, ARRAY_SIZE(SEQ_NT36525B_086), 0, },
	{SEQ_NT36525B_087, ARRAY_SIZE(SEQ_NT36525B_087), 0, },
	{SEQ_NT36525B_088, ARRAY_SIZE(SEQ_NT36525B_088), 0, },
	{SEQ_NT36525B_089, ARRAY_SIZE(SEQ_NT36525B_089), 0, },
	{SEQ_NT36525B_090, ARRAY_SIZE(SEQ_NT36525B_090), 0, },
	{SEQ_NT36525B_091, ARRAY_SIZE(SEQ_NT36525B_091), 0, },
	{SEQ_NT36525B_092, ARRAY_SIZE(SEQ_NT36525B_092), 0, },
	{SEQ_NT36525B_093, ARRAY_SIZE(SEQ_NT36525B_093), 0, },
	{SEQ_NT36525B_094, ARRAY_SIZE(SEQ_NT36525B_094), 0, },
	{SEQ_NT36525B_095, ARRAY_SIZE(SEQ_NT36525B_095), 0, },
	{SEQ_NT36525B_096, ARRAY_SIZE(SEQ_NT36525B_096), 0, },
	{SEQ_NT36525B_097, ARRAY_SIZE(SEQ_NT36525B_097), 0, },
	{SEQ_NT36525B_098, ARRAY_SIZE(SEQ_NT36525B_098), 0, },
	{SEQ_NT36525B_099, ARRAY_SIZE(SEQ_NT36525B_099), 0, },
	{SEQ_NT36525B_100, ARRAY_SIZE(SEQ_NT36525B_100), 0, },
	{SEQ_NT36525B_101, ARRAY_SIZE(SEQ_NT36525B_101), 0, },
	{SEQ_NT36525B_102, ARRAY_SIZE(SEQ_NT36525B_102), 0, },
	{SEQ_NT36525B_103, ARRAY_SIZE(SEQ_NT36525B_103), 0, },
	{SEQ_NT36525B_104, ARRAY_SIZE(SEQ_NT36525B_104), 0, },
	{SEQ_NT36525B_105, ARRAY_SIZE(SEQ_NT36525B_105), 0, },
	{SEQ_NT36525B_106, ARRAY_SIZE(SEQ_NT36525B_106), 0, },
	{SEQ_NT36525B_107, ARRAY_SIZE(SEQ_NT36525B_107), 0, },
	{SEQ_NT36525B_108, ARRAY_SIZE(SEQ_NT36525B_108), 0, },
	{SEQ_NT36525B_109, ARRAY_SIZE(SEQ_NT36525B_109), 0, },
	{SEQ_NT36525B_110, ARRAY_SIZE(SEQ_NT36525B_110), 0, },
	{SEQ_NT36525B_111, ARRAY_SIZE(SEQ_NT36525B_111), 0, },
	{SEQ_NT36525B_112, ARRAY_SIZE(SEQ_NT36525B_112), 0, },
	{SEQ_NT36525B_113, ARRAY_SIZE(SEQ_NT36525B_113), 0, },
	{SEQ_NT36525B_114, ARRAY_SIZE(SEQ_NT36525B_114), 0, },
	{SEQ_NT36525B_115, ARRAY_SIZE(SEQ_NT36525B_115), 0, },
	{SEQ_NT36525B_116, ARRAY_SIZE(SEQ_NT36525B_116), 0, },
	{SEQ_NT36525B_117, ARRAY_SIZE(SEQ_NT36525B_117), 0, },
	{SEQ_NT36525B_118, ARRAY_SIZE(SEQ_NT36525B_118), 0, },
	{SEQ_NT36525B_119, ARRAY_SIZE(SEQ_NT36525B_119), 0, },
	{SEQ_NT36525B_120, ARRAY_SIZE(SEQ_NT36525B_120), 0, },
	{SEQ_NT36525B_121, ARRAY_SIZE(SEQ_NT36525B_121), 0, },
	{SEQ_NT36525B_122, ARRAY_SIZE(SEQ_NT36525B_122), 0, },
	{SEQ_NT36525B_123, ARRAY_SIZE(SEQ_NT36525B_123), 0, },
	{SEQ_NT36525B_124, ARRAY_SIZE(SEQ_NT36525B_124), 0, },
	{SEQ_NT36525B_125, ARRAY_SIZE(SEQ_NT36525B_125), 0, },
	{SEQ_NT36525B_126, ARRAY_SIZE(SEQ_NT36525B_126), 0, },
	{SEQ_NT36525B_127, ARRAY_SIZE(SEQ_NT36525B_127), 0, },
	{SEQ_NT36525B_128, ARRAY_SIZE(SEQ_NT36525B_128), 0, },
	{SEQ_NT36525B_129, ARRAY_SIZE(SEQ_NT36525B_129), 0, },
	{SEQ_NT36525B_130, ARRAY_SIZE(SEQ_NT36525B_130), 0, },
	{SEQ_NT36525B_131, ARRAY_SIZE(SEQ_NT36525B_131), 0, },
	{SEQ_NT36525B_132, ARRAY_SIZE(SEQ_NT36525B_132), 0, },
	{SEQ_NT36525B_133, ARRAY_SIZE(SEQ_NT36525B_133), 0, },
	{SEQ_NT36525B_134, ARRAY_SIZE(SEQ_NT36525B_134), 0, },
	{SEQ_NT36525B_135, ARRAY_SIZE(SEQ_NT36525B_135), 0, },
	{SEQ_NT36525B_136, ARRAY_SIZE(SEQ_NT36525B_136), 0, },
	{SEQ_NT36525B_137, ARRAY_SIZE(SEQ_NT36525B_137), 0, },
	{SEQ_NT36525B_138, ARRAY_SIZE(SEQ_NT36525B_138), 0, },
	{SEQ_NT36525B_139, ARRAY_SIZE(SEQ_NT36525B_139), 0, },
	{SEQ_NT36525B_140, ARRAY_SIZE(SEQ_NT36525B_140), 0, },
	{SEQ_NT36525B_141, ARRAY_SIZE(SEQ_NT36525B_141), 0, },
	{SEQ_NT36525B_142, ARRAY_SIZE(SEQ_NT36525B_142), 0, },
	{SEQ_NT36525B_143, ARRAY_SIZE(SEQ_NT36525B_143), 0, },
	{SEQ_NT36525B_144, ARRAY_SIZE(SEQ_NT36525B_144), 0, },
	{SEQ_NT36525B_145, ARRAY_SIZE(SEQ_NT36525B_145), 0, },
	{SEQ_NT36525B_146, ARRAY_SIZE(SEQ_NT36525B_146), 0, },
	{SEQ_NT36525B_147, ARRAY_SIZE(SEQ_NT36525B_147), 0, },
	{SEQ_NT36525B_148, ARRAY_SIZE(SEQ_NT36525B_148), 0, },
	{SEQ_NT36525B_149, ARRAY_SIZE(SEQ_NT36525B_149), 0, },
	{SEQ_NT36525B_150, ARRAY_SIZE(SEQ_NT36525B_150), 0, },
	{SEQ_NT36525B_151, ARRAY_SIZE(SEQ_NT36525B_151), 0, },
	{SEQ_NT36525B_152, ARRAY_SIZE(SEQ_NT36525B_152), 0, },
	{SEQ_NT36525B_153, ARRAY_SIZE(SEQ_NT36525B_153), 0, },
	{SEQ_NT36525B_154, ARRAY_SIZE(SEQ_NT36525B_154), 0, },
	{SEQ_NT36525B_155, ARRAY_SIZE(SEQ_NT36525B_155), 0, },
	{SEQ_NT36525B_156, ARRAY_SIZE(SEQ_NT36525B_156), 0, },
	{SEQ_NT36525B_157, ARRAY_SIZE(SEQ_NT36525B_157), 0, },
	{SEQ_NT36525B_158, ARRAY_SIZE(SEQ_NT36525B_158), 0, },
	{SEQ_NT36525B_159, ARRAY_SIZE(SEQ_NT36525B_159), 0, },
	{SEQ_NT36525B_160, ARRAY_SIZE(SEQ_NT36525B_160), 0, },
	{SEQ_NT36525B_161, ARRAY_SIZE(SEQ_NT36525B_161), 0, },
	{SEQ_NT36525B_162, ARRAY_SIZE(SEQ_NT36525B_162), 0, },
	{SEQ_NT36525B_163, ARRAY_SIZE(SEQ_NT36525B_163), 0, },
	{SEQ_NT36525B_164, ARRAY_SIZE(SEQ_NT36525B_164), 0, },
	{SEQ_NT36525B_165, ARRAY_SIZE(SEQ_NT36525B_165), 0, },
	{SEQ_NT36525B_166, ARRAY_SIZE(SEQ_NT36525B_166), 0, },
	{SEQ_NT36525B_167, ARRAY_SIZE(SEQ_NT36525B_167), 0, },
	{SEQ_NT36525B_168, ARRAY_SIZE(SEQ_NT36525B_168), 0, },
	{SEQ_NT36525B_169, ARRAY_SIZE(SEQ_NT36525B_169), 0, },
	{SEQ_NT36525B_170, ARRAY_SIZE(SEQ_NT36525B_170), 0, },
	{SEQ_NT36525B_171, ARRAY_SIZE(SEQ_NT36525B_171), 0, },
	{SEQ_NT36525B_172, ARRAY_SIZE(SEQ_NT36525B_172), 0, },
	{SEQ_NT36525B_173, ARRAY_SIZE(SEQ_NT36525B_173), 0, },
	{SEQ_NT36525B_174, ARRAY_SIZE(SEQ_NT36525B_174), 0, },
	{SEQ_NT36525B_175, ARRAY_SIZE(SEQ_NT36525B_175), 0, },
	{SEQ_NT36525B_176, ARRAY_SIZE(SEQ_NT36525B_176), 0, },
	{SEQ_NT36525B_177, ARRAY_SIZE(SEQ_NT36525B_177), 0, },
	{SEQ_NT36525B_178, ARRAY_SIZE(SEQ_NT36525B_178), 0, },
	{SEQ_NT36525B_179, ARRAY_SIZE(SEQ_NT36525B_179), 0, },
	{SEQ_NT36525B_180, ARRAY_SIZE(SEQ_NT36525B_180), 0, },
	{SEQ_NT36525B_181, ARRAY_SIZE(SEQ_NT36525B_181), 0, },
	{SEQ_NT36525B_182, ARRAY_SIZE(SEQ_NT36525B_182), 0, },
	{SEQ_NT36525B_183, ARRAY_SIZE(SEQ_NT36525B_183), 0, },
	{SEQ_NT36525B_184, ARRAY_SIZE(SEQ_NT36525B_184), 0, },
	{SEQ_NT36525B_185, ARRAY_SIZE(SEQ_NT36525B_185), 0, },
	{SEQ_NT36525B_186, ARRAY_SIZE(SEQ_NT36525B_186), 0, },
	{SEQ_NT36525B_187, ARRAY_SIZE(SEQ_NT36525B_187), 0, },
	{SEQ_NT36525B_188, ARRAY_SIZE(SEQ_NT36525B_188), 0, },
	{SEQ_NT36525B_189, ARRAY_SIZE(SEQ_NT36525B_189), 0, },
	{SEQ_NT36525B_190, ARRAY_SIZE(SEQ_NT36525B_190), 0, },
	{SEQ_NT36525B_191, ARRAY_SIZE(SEQ_NT36525B_191), 0, },
	{SEQ_NT36525B_192, ARRAY_SIZE(SEQ_NT36525B_192), 0, },
	{SEQ_NT36525B_193, ARRAY_SIZE(SEQ_NT36525B_193), 0, },
	{SEQ_NT36525B_194, ARRAY_SIZE(SEQ_NT36525B_194), 0, },
	{SEQ_NT36525B_195, ARRAY_SIZE(SEQ_NT36525B_195), 0, },
	{SEQ_NT36525B_196, ARRAY_SIZE(SEQ_NT36525B_196), 0, },
	{SEQ_NT36525B_197, ARRAY_SIZE(SEQ_NT36525B_197), 0, },
	{SEQ_NT36525B_198, ARRAY_SIZE(SEQ_NT36525B_198), 0, },
	{SEQ_NT36525B_199, ARRAY_SIZE(SEQ_NT36525B_199), 0, },
	{SEQ_NT36525B_200, ARRAY_SIZE(SEQ_NT36525B_200), 0, },
	{SEQ_NT36525B_201, ARRAY_SIZE(SEQ_NT36525B_201), 0, },
	{SEQ_NT36525B_202, ARRAY_SIZE(SEQ_NT36525B_202), 0, },
	{SEQ_NT36525B_203, ARRAY_SIZE(SEQ_NT36525B_203), 0, },
	{SEQ_NT36525B_204, ARRAY_SIZE(SEQ_NT36525B_204), 0, },
	{SEQ_NT36525B_205, ARRAY_SIZE(SEQ_NT36525B_205), 0, },
	{SEQ_NT36525B_206, ARRAY_SIZE(SEQ_NT36525B_206), 0, },
	{SEQ_NT36525B_207, ARRAY_SIZE(SEQ_NT36525B_207), 0, },
	{SEQ_NT36525B_208, ARRAY_SIZE(SEQ_NT36525B_208), 0, },
	{SEQ_NT36525B_209, ARRAY_SIZE(SEQ_NT36525B_209), 0, },
	{SEQ_NT36525B_210, ARRAY_SIZE(SEQ_NT36525B_210), 0, },
	{SEQ_NT36525B_211, ARRAY_SIZE(SEQ_NT36525B_211), 0, },
	{SEQ_NT36525B_212, ARRAY_SIZE(SEQ_NT36525B_212), 0, },
	{SEQ_NT36525B_213, ARRAY_SIZE(SEQ_NT36525B_213), 0, },
	{SEQ_NT36525B_214, ARRAY_SIZE(SEQ_NT36525B_214), 0, },
	{SEQ_NT36525B_215, ARRAY_SIZE(SEQ_NT36525B_215), 0, },
	{SEQ_NT36525B_216, ARRAY_SIZE(SEQ_NT36525B_216), 0, },
	{SEQ_NT36525B_217, ARRAY_SIZE(SEQ_NT36525B_217), 0, },
	{SEQ_NT36525B_218, ARRAY_SIZE(SEQ_NT36525B_218), 0, },
	{SEQ_NT36525B_219, ARRAY_SIZE(SEQ_NT36525B_219), 0, },
};

/* DO NOT REMOVE: back to page 1 for setting DCS commands */
static unsigned char SEQ_NT36525B_BACK_TO_PAGE_1_A[] = {
	0xFF,
	0x10,
};

static unsigned char SEQ_NT36525B_BACK_TO_PAGE_1_B[] = {
	0xFB,
	0x01,
};

static unsigned int brightness_table[EXTEND_BRIGHTNESS + 1] = {
	0,
	1, 1, 2, 3, 3, 4, 5, 5, 6, 7, /* 1: 1 */
	7, 8, 9, 9, 10, 11, 11, 12, 13, 14,
	14, 15, 16, 16, 17, 18, 18, 19, 20, 20,
	21, 22, 22, 23, 24, 24, 25, 26, 27, 27,
	28, 29, 29, 30, 31, 31, 32, 33, 33, 34,
	35, 35, 36, 37, 37, 38, 39, 40, 40, 41,
	42, 42, 43, 44, 44, 45, 46, 46, 47, 48,
	48, 49, 50, 51, 51, 52, 53, 53, 54, 55,
	55, 56, 57, 57, 58, 59, 59, 60, 61, 61,
	62, 63, 64, 64, 65, 66, 66, 67, 68, 68,
	69, 70, 70, 71, 72, 72, 73, 74, 74, 75,
	76, 77, 77, 78, 79, 79, 80, 81, 81, 82,
	83, 83, 84, 85, 85, 86, 87, 88, 88, 89, /* 128: 88 */
	90, 91, 92, 93, 94, 95, 96, 97, 98, 99,
	100, 101, 102, 103, 104, 105, 106, 107, 108, 109,
	110, 111, 112, 113, 114, 115, 116, 117, 118, 118,
	119, 120, 121, 122, 123, 124, 125, 126, 127, 128,
	129, 130, 131, 132, 133, 134, 135, 136, 137, 138,
	139, 140, 141, 142, 143, 144, 145, 146, 147, 148,
	149, 149, 150, 151, 152, 153, 154, 155, 156, 157,
	158, 159, 160, 161, 162, 163, 164, 165, 166, 167,
	168, 169, 170, 171, 172, 173, 174, 175, 176, 177,
	178, 179, 180, 180, 181, 182, 183, 184, 185, 186,
	187, 188, 189, 190, 191, 192, 193, 194, 195, 196,
	197, 198, 199, 200, 201, 202, 203, 204, 205, 206,
	207, 208, 209, 210, 211, 211, 211, 211, 211, 211, /* 255: 211 */
	211, 211, 211, 211, 211, 211, 211, 211, 211, 211,
	211, 211, 211, 211, 211, 211, 211, 211, 211, 211,
	211, 211, 211, 211, 211, 211, 211, 211, 211, 211,
	211, 211, 211, 211, 211, 211, 211, 211, 211, 211,
	211, 211, 211, 211, 211, 254,
};

#endif /* __NT36525B_PARAM_H__ */
