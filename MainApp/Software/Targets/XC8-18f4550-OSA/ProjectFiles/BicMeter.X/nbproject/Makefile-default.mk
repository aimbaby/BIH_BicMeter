#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Include project Makefile
ifeq "${IGNORE_LOCAL}" "TRUE"
# do not include local makefile. User is passing all local related variables already
else
include Makefile
# Include makefile containing local settings
ifeq "$(wildcard nbproject/Makefile-local-default.mk)" "nbproject/Makefile-local-default.mk"
include nbproject/Makefile-local-default.mk
endif
endif

# Environment
MKDIR=gnumkdir -p
RM=rm -f 
MV=mv 
CP=cp 

# Macros
CND_CONF=default
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
IMAGE_TYPE=debug
OUTPUT_SUFFIX=elf
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=elf
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=--mafrlcsj
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=../../../../Common/App/APP.c ../../../../Common/Driver/BCDdisplay/BCDdisplay.c ../../../../Common/Driver/SpeedCalc/SpeedCalc.c ../../../../Common/Interrupts/AppInterrupts.c ../../../../OS/Scheduler/Scheduler.c ../../HWIsource/HWI_DIGITAL.c ../../HWIsource/HWI_Interrupts.c main.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/_ext/2107172035/APP.p1 ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1 ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1 ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1 ${OBJECTDIR}/_ext/1581091472/Scheduler.p1 ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1 ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1 ${OBJECTDIR}/main.p1
POSSIBLE_DEPFILES=${OBJECTDIR}/_ext/2107172035/APP.p1.d ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1.d ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1.d ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1.d ${OBJECTDIR}/_ext/1581091472/Scheduler.p1.d ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1.d ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1.d ${OBJECTDIR}/main.p1.d

# Object Files
OBJECTFILES=${OBJECTDIR}/_ext/2107172035/APP.p1 ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1 ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1 ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1 ${OBJECTDIR}/_ext/1581091472/Scheduler.p1 ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1 ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1 ${OBJECTDIR}/main.p1

# Source Files
SOURCEFILES=../../../../Common/App/APP.c ../../../../Common/Driver/BCDdisplay/BCDdisplay.c ../../../../Common/Driver/SpeedCalc/SpeedCalc.c ../../../../Common/Interrupts/AppInterrupts.c ../../../../OS/Scheduler/Scheduler.c ../../HWIsource/HWI_DIGITAL.c ../../HWIsource/HWI_Interrupts.c main.c


CFLAGS=
ASFLAGS=
LDLIBSOPTIONS=

############# Tool locations ##########################################
# If you copy a project from one host to another, the path where the  #
# compiler is installed may be different.                             #
# If you open this project with MPLAB X in the new host, this         #
# makefile will be regenerated and the paths will be corrected.       #
#######################################################################
# fixDeps replaces a bunch of sed/cat/printf statements that slow down the build
FIXDEPS=fixDeps

.build-conf:  ${BUILD_SUBPROJECTS}
ifneq ($(INFORMATION_MESSAGE), )
	@echo $(INFORMATION_MESSAGE)
endif
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F4520
# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/_ext/2107172035/APP.p1: ../../../../Common/App/APP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2107172035" 
	@${RM} ${OBJECTDIR}/_ext/2107172035/APP.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2107172035/APP.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2107172035/APP.p1  ../../../../Common/App/APP.c 
	@-${MV} ${OBJECTDIR}/_ext/2107172035/APP.d ${OBJECTDIR}/_ext/2107172035/APP.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2107172035/APP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1: ../../../../Common/Driver/BCDdisplay/BCDdisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1293405090" 
	@${RM} ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1  ../../../../Common/Driver/BCDdisplay/BCDdisplay.c 
	@-${MV} ${OBJECTDIR}/_ext/1293405090/BCDdisplay.d ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1: ../../../../Common/Driver/SpeedCalc/SpeedCalc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1958996569" 
	@${RM} ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1  ../../../../Common/Driver/SpeedCalc/SpeedCalc.c 
	@-${MV} ${OBJECTDIR}/_ext/1958996569/SpeedCalc.d ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1: ../../../../Common/Interrupts/AppInterrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925265964" 
	@${RM} ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1  ../../../../Common/Interrupts/AppInterrupts.c 
	@-${MV} ${OBJECTDIR}/_ext/1925265964/AppInterrupts.d ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1581091472/Scheduler.p1: ../../../../OS/Scheduler/Scheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1581091472" 
	@${RM} ${OBJECTDIR}/_ext/1581091472/Scheduler.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1581091472/Scheduler.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1581091472/Scheduler.p1  ../../../../OS/Scheduler/Scheduler.c 
	@-${MV} ${OBJECTDIR}/_ext/1581091472/Scheduler.d ${OBJECTDIR}/_ext/1581091472/Scheduler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1581091472/Scheduler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1: ../../HWIsource/HWI_DIGITAL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1657922581" 
	@${RM} ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1  ../../HWIsource/HWI_DIGITAL.c 
	@-${MV} ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.d ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1: ../../HWIsource/HWI_Interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1657922581" 
	@${RM} ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1  ../../HWIsource/HWI_Interrupts.c 
	@-${MV} ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.d ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
else
${OBJECTDIR}/_ext/2107172035/APP.p1: ../../../../Common/App/APP.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/2107172035" 
	@${RM} ${OBJECTDIR}/_ext/2107172035/APP.p1.d 
	@${RM} ${OBJECTDIR}/_ext/2107172035/APP.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/2107172035/APP.p1  ../../../../Common/App/APP.c 
	@-${MV} ${OBJECTDIR}/_ext/2107172035/APP.d ${OBJECTDIR}/_ext/2107172035/APP.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/2107172035/APP.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1: ../../../../Common/Driver/BCDdisplay/BCDdisplay.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1293405090" 
	@${RM} ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1  ../../../../Common/Driver/BCDdisplay/BCDdisplay.c 
	@-${MV} ${OBJECTDIR}/_ext/1293405090/BCDdisplay.d ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1293405090/BCDdisplay.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1: ../../../../Common/Driver/SpeedCalc/SpeedCalc.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1958996569" 
	@${RM} ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1  ../../../../Common/Driver/SpeedCalc/SpeedCalc.c 
	@-${MV} ${OBJECTDIR}/_ext/1958996569/SpeedCalc.d ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1958996569/SpeedCalc.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1: ../../../../Common/Interrupts/AppInterrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1925265964" 
	@${RM} ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1  ../../../../Common/Interrupts/AppInterrupts.c 
	@-${MV} ${OBJECTDIR}/_ext/1925265964/AppInterrupts.d ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1925265964/AppInterrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1581091472/Scheduler.p1: ../../../../OS/Scheduler/Scheduler.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1581091472" 
	@${RM} ${OBJECTDIR}/_ext/1581091472/Scheduler.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1581091472/Scheduler.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1581091472/Scheduler.p1  ../../../../OS/Scheduler/Scheduler.c 
	@-${MV} ${OBJECTDIR}/_ext/1581091472/Scheduler.d ${OBJECTDIR}/_ext/1581091472/Scheduler.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1581091472/Scheduler.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1: ../../HWIsource/HWI_DIGITAL.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1657922581" 
	@${RM} ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1  ../../HWIsource/HWI_DIGITAL.c 
	@-${MV} ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.d ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1657922581/HWI_DIGITAL.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1: ../../HWIsource/HWI_Interrupts.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/1657922581" 
	@${RM} ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1.d 
	@${RM} ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1  ../../HWIsource/HWI_Interrupts.c 
	@-${MV} ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.d ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/_ext/1657922581/HWI_Interrupts.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
${OBJECTDIR}/main.p1: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.p1.d 
	@${RM} ${OBJECTDIR}/main.p1 
	${MP_CC} --pass1 $(MP_EXTRA_CC_PRE) --chip=$(MP_PROCESSOR_OPTION) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib $(COMPARISON_BUILD)  --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"    -o${OBJECTDIR}/main.p1  main.c 
	@-${MV} ${OBJECTDIR}/main.d ${OBJECTDIR}/main.p1.d 
	@${FIXDEPS} ${OBJECTDIR}/main.p1.d $(SILENT) -rsi ${MP_CC_DIR}../  
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.map  -D__DEBUG=1 --debugger=none  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"        $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	@${RM} dist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.hex 
	
else
dist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_CC} $(MP_EXTRA_LD_PRE) --chip=$(MP_PROCESSOR_OPTION) -G -mdist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.map  --double=24 --float=24 --emi=wordwrite --opt=+asm,+asmfile,-speed,+space,-debug,-local --addrqual=ignore --mode=free -P -N255 -I"../../../../" -I"../../../../Common/Link" -I"../../../../Common/Interrupts" -I"../../../../Common/App" -I"../../../../Common/HWIheader" -I"../../../../OS/Scheduler" -I"../../../../Common/Driver" -I"../../../../Common/Driver/SpeedCalc" -I"../../HWIsource" -I"../../../../Common/Driver/BCDdisplay" --warn=0 --asmlist -DXPRJ_default=$(CND_CONF)  --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"     $(COMPARISON_BUILD) --memorysummary dist/${CND_CONF}/${IMAGE_TYPE}/memoryfile.xml -odist/${CND_CONF}/${IMAGE_TYPE}/BicMeter.X.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}     
	
endif


# Subprojects
.build-subprojects:


# Subprojects
.clean-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r build/default
	${RM} -r dist/default

# Enable dependency checking
.dep.inc: .depcheck-impl

DEPFILES=$(shell mplabwildcard ${POSSIBLE_DEPFILES})
ifneq (${DEPFILES},)
include ${DEPFILES}
endif
