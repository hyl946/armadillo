#include "armadillo.h"
#include "linkedlist.h"
#include "instruction.h"

struct testinstr {
	const char *name;
	unsigned int hex;
	unsigned long PC;
};

struct linkedlist *instructions = NULL;

void addinstr(const char *name, unsigned int hex, unsigned long PC){
	if(!instructions)
		return;


	struct testinstr *i = malloc(sizeof(struct testinstr));
	i->name = name;
	i->hex = hex;
	i->PC = PC;

	linkedlist_add(instructions, i);
}

int main(int argc, char **argp, const char **envp){
	instructions = linkedlist_new();


	//addinstr("mov x7, x4", 0xAA0403E7);
	//addinstr("add x0, x0, x1", 0x8B010000);
	addinstr("add x0, x0, #0xfe", 0x9103F800, 0);
	addinstr("add x0, x0, #8388608", 0x91600000, 0);
	addinstr("adds x0, x0, #0xfe", 0xB103F800, 0);
	addinstr("add w0, w0, #0xfe", 0x1103F800, 0);
	addinstr("add w0, w0, #0xfe, lsl #12", 0x1143F800, 0);
	addinstr("add w3, wsp, #0", 0x110003E3, 0);
	addinstr("adds xzr, sp, #4", 0xB10013FF, 0);
	addinstr("sub x4, x2, #4", 0xD1001044, 0);
	addinstr("sub x4, x2, #0x800, lsl 12", 0xD1600044, 0);
	addinstr("sub w5, w11, #20", 0x51005165, 0);
	addinstr("subs w9, w16, #3444", 0x7135D209, 0);
	addinstr("subs x11, x25, #16384", 0xF140132B, 0);
	addinstr("subs wzr, w3, #8192", 0x7140087F, 0);
	addinstr("subs xzr, x14, #4192", 0xF14005DF, 0);
	addinstr("subs xzr, sp, #2048", 0xF12003FF, 0);

	addinstr("and x0, x2, #4", 0x927E0040, 0);
	addinstr("and x6, x18, #-16", 0x927CEE46, 0);
	addinstr("and x25, x22, #8388608", 0x926902D9, 0);
	addinstr("and x25, x22, #-4194304", 0x926AA6D9, 0);
	addinstr("and w8, w14, #1", 0x120001C8, 0);
	addinstr("and w18, w1, #-16", 0x121C6C32, 0);

	addinstr("orr x9, x3, #30", 0xB27F0C69, 0);
	addinstr("orr w20, w0, #-16", 0x321C6C14, 0);
	addinstr("orr w16, w4, #-0x800000", 0x32092090, 0);
	addinstr("orr w4, w31, #0x80000003", 0x32010BE1, 0);
	addinstr("orr x8, xzr, xzr", 0xAA1F03E8, 0);
	


	addinstr("eor wsp, w3, #0x80000003", 0x5201087F, 0);
	addinstr("eor x6, x3, #0xffff", 0xD2403C66, 0);
	addinstr("eor x24, x8, #-0x400000", 0xD26AA518, 0);
	addinstr("ands x0, x1, #0x6", 0xF27F0420, 0);
	addinstr("ands w5, w4, #-0x4", 0x721E7485, 0);

	addinstr("adrp x8, #0x100046000 @ 0x10000a7e8", 0x900001e8, 0x10000a7e8);
	addinstr("adrp x1, #0x10000a000 @ 0x10000a79c", 0x90000001, 0x10000a79c);
	addinstr("sub sp, sp, #0x80", 0xd10203ff, 0);
	

	addinstr("movn w0, #39333", 0x129334A0, 0);
	addinstr("movn x5, #65535", 0x929FFFE5, 0);
	addinstr("movn x19, #3443, lsl #32", 0x92C1AE73, 0);
	addinstr("movn w2, #20, lsl #16", 0x12A00282, 0);
	addinstr("movn x2, #20, lsl #16", 0x92A00282, 0);

	addinstr("movz w0, #40, lsl #16", 0x52A00500, 0);
	addinstr("movz x6, #9833, lsl #48", 0xD2E4CD26, 0);
	addinstr("movz x16, #34335, lsl #32", 0xD2D0C3F0, 0);
	addinstr("movz w4, #2292", 0x52811E84, 0);
	addinstr("movz x21, #2", 0xD2800055, 0);

	addinstr("movk w5, #4943, lsl #16", 0x72A269E5, 0);
	addinstr("movk x10, #2321, lsl #48", 0xF2E1222A, 0);
	addinstr("movk x8, #4848, lsl #32", 0xF2C25E08, 0);
	addinstr("movk x25, #0", 0xF2800019, 0);
	addinstr("movk w23, #2", 0x72800057, 0);

	addinstr("sbfm x0, x2, #4, #5", 0x93441440, 0);
	addinstr("sbfm w3, w14, #4, #6", 0x130419C3, 0);
	addinstr("sbfm x31, x2, #4, #34", 0x9344885F, 0);
	addinstr("sbfm x0, x2, #22, #31", 0x93567C40, 0);
	addinstr("sbfm x31, x2, #4, #0x3f", 0x9344FC5F, 0);
	addinstr("sbfm w31, w2, #4, #0x1f", 0x13047C5F, 0);
	addinstr("sbfm x4, x14, #4, #2", 0x934409C4, 0);
	addinstr("sbfm x8, x1, #32, #24", 0x93606028, 0);
	addinstr("sbfm w21, w13, #16, #8", 0x131021B5, 0);
	addinstr("sbfm x4, x12, #0, #7", 0x93401D84, 0);
	addinstr("sbfm w5, w1, #0, #7", 0x13001C25, 0);
	addinstr("sbfm w0, w6, #0, #15", 0x13003CC0, 0);
	addinstr("sbfm x2, x20, #0, #15", 0x93403E82, 0);
	addinstr("sbfm w3, w4, #0, #31", 0x13007C83, 0);
	addinstr("sbfm x19, x9, #0, #31", 0x93407D3F, 0);
	


	addinstr("bfm x0, x31, #4, #2", 0xB3440BE0, 0);
    addinstr("bfm w3, w31, #4, #2", 0x33040BE3, 0);
    addinstr("bfm x31, x2, #4, #34", 0xB344885F, 0);
    addinstr("bfm x0, x2, #22, #31", 0xB3567C40, 0);
    addinstr("bfm x31, x2, #4, #8", 0xB344205F, 0);
    addinstr("bfm w31, w2, #4, #0x1f", 0x33047C5F, 0);
    addinstr("bfm x4, x14, #4, #2", 0xB34409C4, 0);
    addinstr("bfm x8, x1, #32, #24", 0xB3606028, 0);
    addinstr("bfm w21, w13, #16, #8", 0x331021B5, 0);
    addinstr("bfm x4, x12, #0, #7", 0xB3401D84, 0);
    addinstr("bfm w5, w1, #0, #7", 0x33001C25, 0);
    addinstr("bfm w0, w6, #0, #15", 0x33003CC0, 0);
    addinstr("bfm x2, x20, #0, #15", 0xB3403E82, 0);
    addinstr("bfm w3, w4, #0, #31", 0x33007C83, 0);
    addinstr("bfm x19, x9, #0, #31", 0xB3407D33, 0);



	addinstr("ubfm x3, x4, #8, #7", 0xD3481C83, 0);
    addinstr("ubfm w4, w1, #15, #14", 0x530F3824, 0);
    addinstr("ubfm x0, x31, #4, #2", 0xD3440BE0, 0);
    addinstr("ubfm w3, w31, #4, #2", 0x53040BE3, 0);
    addinstr("ubfm x31, x2, #4, #34", 0xD344885F, 0);
    addinstr("ubfm x0, x2, #22, #31", 0xD3567C40, 0);
    addinstr("ubfm x31, x2, #4, #8", 0xD344205F, 0);
    addinstr("ubfm w31, w2, #4, #0x1f", 0x53047C5F, 0);
    addinstr("ubfm x4, x14, #4, #2", 0xD34409C4, 0);
    addinstr("ubfm x8, x1, #32, #24", 0xD3606028, 0);
    addinstr("ubfm w21, w13, #16, #8", 0x531021B5, 0);
    addinstr("ubfm x4, x12, #0, #7", 0xD3401D84, 0);
    addinstr("ubfm w5, w1, #0, #7", 0x53001C25, 0);
    addinstr("ubfm w0, w6, #5, #15", 0x53053CC0, 0);
    addinstr("ubfm x2, x20, #0, #15", 0xD3403E82, 0);
    addinstr("ubfm w3, w4, #0, #31", 0x53007C83, 0);
    addinstr("ubfm x19, x9, #0, #31", 0xD3407D33, 0);
    addinstr("ubfm w5, w9, #0, #15", 0x53003D25, 0);
    addinstr("ubfm x16, x13, #0, #15", 0xD3403DB0, 0);

	addinstr("extr x5, x2, x11, #3", 0x93CB0C45, 0);
    addinstr("extr w6, w8, w1, #25", 0x13816506, 0);
    addinstr("extr x20, x3, x3, #32", 0x93C38074, 0);
    addinstr("extr w1, w13, w13, #1", 0x138D05A1, 0);

	struct node_t *current = instructions->front;

	while(current){
		struct testinstr *ti = (struct testinstr *)current->data;
		printf("Disassembling %s (aka %#x)... ", ti->name, ti->hex);
		struct instruction *i = instruction_new(ti->hex, ti->PC);
		char *ret = ArmadilloDisassemble(i);
		//printf("ret = %p\n", ret);
		instruction_free(i);
		printf("Disassembled: %s\n\n", ret);
		free(ret);

		current = current->next;
	}

	linkedlist_free(instructions);

	/*unsigned int instrs[] = { 0xAA0403E7, 0x8B010000, 0x9103F800, 0x91600000, 0xB103F800, 0x1103F800, 0x1143F800, 0x110003E3, 0xAA1C03E7, 0x10020017, 0x10FE0017, 0xB0001A24, 0xB0FFDDF5, 0x9000003E, 0x90FFFFFE, 0x3000002F, 0x70FFFFC3 };
	const char *instrstrs[] = { "mov x7, x4", 
								"add x0, x0, x1",
								"add x0, x0, #0xfe",
								"add x0, x0, #8388608",
								"adds x0, x0, #0xfe",
								"add w0, w0, #0xfe",
								"add w0, w0, #0xfe, lsl #12",
								"add w3, wsp, #0",
								"mov x7, x28",
								"adr x23, 0x4000",
								"adr x23, -0x4000",
								"adrp x4, 0x345000",
   								"adrp x21, -0x443000",
								"adrp x30, 0x4000",
								"adrp x30, -0x4000",
								"adr x15, 0x5",
								"adr x3, -0x5"
	};

	for(int i=0; i<sizeof(instrs)/sizeof(unsigned int); i++){
		printf("Disassembling %s (aka %#x)... ", instrstrs[i], instrs[i]);
		char *ret = disassemble(instrs[i]);
		printf("Disassembled: %s\n\n", ret);
		free(ret);
	}
	*/
	return 0;
}
