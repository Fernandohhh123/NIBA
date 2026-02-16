#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "code_generate.h"
#include "binary_instructions.h"
#include "parser.h"

void buffer_init(Binary_code* buffer){
    buffer->total_space = 16;
    buffer->use_space = 0;
    buffer->data = malloc(buffer->total_space);

    if(!buffer->data){
        perror("Error de reserva de memoria");
        exit(1);
    }

}


void buffer_push(Binary_code* buffer, uint8_t instruction){
    //si esta lleno, se duplica la capacidad
    if(buffer->use_space > buffer->total_space){
        buffer->total_space = buffer->total_space * 2;

        uint8_t *new_data = realloc(buffer->data, buffer->total_space);

        if(!new_data){
            perror("No de ha podido expandir el buffer");
            exit(1);
        }

        buffer->data = new_data;
    }

    buffer->data[buffer->use_space] = instruction;
    buffer->use_space ++;
}



void buffer_free(Binary_code* buffer){
    free(buffer->data);
    buffer->data = NULL;
    buffer->use_space = 0;
    buffer->total_space = 0;
}


void instruction_converter(ListaToken* tokens, Binary_code* buffer){
    uint8_t binary_instruction = 0x00;
    uint8_t binary_opcode = 0x00;
    uint8_t binary_operand = 0x00;

    if(es_nodo_vacio(tokens) != 0){
        perror("Nodo tokens en code_generate esta vacio");
        exit(1);
    }

    while(tokens != NULL){
        if(tokens->tipo == TOKEN_INSTRUCCION_CON_OPERANDO){
            binary_opcode = converter_ico(tokens->lexema);

            while(tokens->tipo != TOKEN_OPERANDO){
                tokens = tokens->siguiente;
            }

            binary_operand = get_operand(tokens->lexema);
        } else if(tokens->tipo == TOKEN_INSTRUCCION_SIN_OPERANDO){
            binary_opcode = converter_iso(tokens->lexema);
            binary_operand = 0;
        }

        binary_instruction = juntar_opcode_operando(binary_opcode, binary_operand);
        //printf("%x\n", binary_instruction);

        buffer_push(buffer, binary_instruction);

        binary_instruction = 0x00;
        binary_opcode = 0x00;
        binary_operand = 0x00;

        tokens = tokens->siguiente;
    }
}


uint8_t converter_ico(char *lexema){
    if(strcmp(lexema, "nand") == 0){
        return 0x1;
    }
    else if(strcmp(lexema, "add") == 0){
        return 0x2;
    }
    else if(strcmp(lexema, "lda") == 0){
        return 0x3;
    }
    else if(strcmp(lexema, "jpi") == 0){
        return 0xC;
    }
    else if(strcmp(lexema, "jpc") == 0){
        return 0xD;
    }
    else if(strcmp(lexema, "jpz") == 0){
        return 0xE;
    }
    else{
        perror("Instruccion ico no encontrada\n");
        exit(1);
    }
}

uint8_t get_operand(char* lexema){
    return atoi(lexema);
}

uint8_t converter_iso(char* lexema){
    if(strcmp(lexema, "not") == 0){
        return 0;
    }
    else if(strcmp(lexema, "outa") == 0){
        return 0x4;
    }
    else if(strcmp(lexema, "outb") == 0){
        return 0x5;
    }
    else if(strcmp(lexema, "ina") == 0){
        return 0x6;
    }
    else if(strcmp(lexema, "rd") == 0){
        return 0x7;
    }
    else if(strcmp(lexema, "ra") == 0){
        return 0x8;
    }
    else if(strcmp(lexema, "ldra") == 0){
        return 0x9;
    }
    else{
        perror("Instruccion iso no encontrada\n");
        exit(1);
    }
}




/*
 Desplaza el opcode 4 bita a la izquierda y hace OR con el operando

 T1 opcode = 0000 XXXX
 T2 opcode = XXXX 0000
 T3 opcode = (XXXX 0000) or operando = (0000 YYYY)
 T4 Instruccion = XXXX YYYY = opcode:operando
 */
uint8_t juntar_opcode_operando(uint8_t opcode, uint8_t operando){
    return (opcode << 4) | operando;
}
