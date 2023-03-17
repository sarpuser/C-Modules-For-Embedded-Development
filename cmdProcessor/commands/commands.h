/* 
 * File:   commands.h
 * Author: Sarp User
 *
 * Created on March 16, 2023, 8:54 PM
 */

#ifndef COMMANDS_H
#define	COMMANDS_H

#include <stdint.h>

#include "../cmdProcessor.h"
#include "../cmdProcessor_config.h"

/*
 * Custom Command Example - Place in this file (commands.h)
 * 
 * static command_t myCmd = {"myCmdName", myCmdFunction, "My command description", "My command parameter information", NULL};
 *                NO_PARAMS_INFO_STRING can be used to indicate that a command takes no parameters^
 * 
 * void myCmdFunction (uint8_t argc, char* argv[]);
 */

/*
 * Custom Command Example - Place in registerCustomCommands() in commands.c
 * 
 * CMD_PROCESSOR_RegisterCommand(&myCmd);
 */

void registerCustomCommands ();

#endif	/* COMMANDS_H */

