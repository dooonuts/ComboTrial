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
OUTPUT_SUFFIX=cof
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ComboTrial.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
else
IMAGE_TYPE=production
OUTPUT_SUFFIX=hex
DEBUGGABLE_SUFFIX=cof
FINAL_IMAGE=dist/${CND_CONF}/${IMAGE_TYPE}/ComboTrial.${IMAGE_TYPE}.${OUTPUT_SUFFIX}
endif

ifeq ($(COMPARE_BUILD), true)
COMPARISON_BUILD=
else
COMPARISON_BUILD=
endif

# Object Directory
OBJECTDIR=build/${CND_CONF}/${IMAGE_TYPE}

# Distribution Directory
DISTDIR=dist/${CND_CONF}/${IMAGE_TYPE}

# Source Files Quoted if spaced
SOURCEFILES_QUOTED_IF_SPACED=ADASfxns.c ADAS1000.c Communication.c Lcd.c main.c ../Matts_.X/Serial.c ../Matts_.X/RN.c mainbrain.c Pacing.c

# Object Files Quoted if spaced
OBJECTFILES_QUOTED_IF_SPACED=${OBJECTDIR}/ADASfxns.o ${OBJECTDIR}/ADAS1000.o ${OBJECTDIR}/Communication.o ${OBJECTDIR}/Lcd.o ${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/178502183/Serial.o ${OBJECTDIR}/_ext/178502183/RN.o ${OBJECTDIR}/mainbrain.o ${OBJECTDIR}/Pacing.o
POSSIBLE_DEPFILES=${OBJECTDIR}/ADASfxns.o.d ${OBJECTDIR}/ADAS1000.o.d ${OBJECTDIR}/Communication.o.d ${OBJECTDIR}/Lcd.o.d ${OBJECTDIR}/main.o.d ${OBJECTDIR}/_ext/178502183/Serial.o.d ${OBJECTDIR}/_ext/178502183/RN.o.d ${OBJECTDIR}/mainbrain.o.d ${OBJECTDIR}/Pacing.o.d

# Object Files
OBJECTFILES=${OBJECTDIR}/ADASfxns.o ${OBJECTDIR}/ADAS1000.o ${OBJECTDIR}/Communication.o ${OBJECTDIR}/Lcd.o ${OBJECTDIR}/main.o ${OBJECTDIR}/_ext/178502183/Serial.o ${OBJECTDIR}/_ext/178502183/RN.o ${OBJECTDIR}/mainbrain.o ${OBJECTDIR}/Pacing.o

# Source Files
SOURCEFILES=ADASfxns.c ADAS1000.c Communication.c Lcd.c main.c ../Matts_.X/Serial.c ../Matts_.X/RN.c mainbrain.c Pacing.c


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
	${MAKE}  -f nbproject/Makefile-default.mk dist/${CND_CONF}/${IMAGE_TYPE}/ComboTrial.${IMAGE_TYPE}.${OUTPUT_SUFFIX}

MP_PROCESSOR_OPTION=18F46K22
MP_PROCESSOR_OPTION_LD=18f46k22
MP_LINKER_DEBUG_OPTION=  -u_DEBUGSTACK
# ------------------------------------------------------------------------------------
# Rules for buildStep: assemble
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
else
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: compile
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
${OBJECTDIR}/ADASfxns.o: ADASfxns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADASfxns.o.d 
	@${RM} ${OBJECTDIR}/ADASfxns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/ADASfxns.o   ADASfxns.c 
	@${DEP_GEN} -d ${OBJECTDIR}/ADASfxns.o 
	@${FIXDEPS} "${OBJECTDIR}/ADASfxns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/ADAS1000.o: ADAS1000.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADAS1000.o.d 
	@${RM} ${OBJECTDIR}/ADAS1000.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/ADAS1000.o   ADAS1000.c 
	@${DEP_GEN} -d ${OBJECTDIR}/ADAS1000.o 
	@${FIXDEPS} "${OBJECTDIR}/ADAS1000.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Communication.o: Communication.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Communication.o.d 
	@${RM} ${OBJECTDIR}/Communication.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Communication.o   Communication.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Communication.o 
	@${FIXDEPS} "${OBJECTDIR}/Communication.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Lcd.o: Lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Lcd.o.d 
	@${RM} ${OBJECTDIR}/Lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Lcd.o   Lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/Lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/178502183/Serial.o: ../Matts_.X/Serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/178502183" 
	@${RM} ${OBJECTDIR}/_ext/178502183/Serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/178502183/Serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/178502183/Serial.o   ../Matts_.X/Serial.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/178502183/Serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/178502183/Serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/178502183/RN.o: ../Matts_.X/RN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/178502183" 
	@${RM} ${OBJECTDIR}/_ext/178502183/RN.o.d 
	@${RM} ${OBJECTDIR}/_ext/178502183/RN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/178502183/RN.o   ../Matts_.X/RN.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/178502183/RN.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/178502183/RN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/mainbrain.o: mainbrain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mainbrain.o.d 
	@${RM} ${OBJECTDIR}/mainbrain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/mainbrain.o   mainbrain.c 
	@${DEP_GEN} -d ${OBJECTDIR}/mainbrain.o 
	@${FIXDEPS} "${OBJECTDIR}/mainbrain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Pacing.o: Pacing.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Pacing.o.d 
	@${RM} ${OBJECTDIR}/Pacing.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -D__DEBUG -D__MPLAB_DEBUGGER_PK3=1 -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Pacing.o   Pacing.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Pacing.o 
	@${FIXDEPS} "${OBJECTDIR}/Pacing.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
else
${OBJECTDIR}/ADASfxns.o: ADASfxns.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADASfxns.o.d 
	@${RM} ${OBJECTDIR}/ADASfxns.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/ADASfxns.o   ADASfxns.c 
	@${DEP_GEN} -d ${OBJECTDIR}/ADASfxns.o 
	@${FIXDEPS} "${OBJECTDIR}/ADASfxns.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/ADAS1000.o: ADAS1000.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/ADAS1000.o.d 
	@${RM} ${OBJECTDIR}/ADAS1000.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/ADAS1000.o   ADAS1000.c 
	@${DEP_GEN} -d ${OBJECTDIR}/ADAS1000.o 
	@${FIXDEPS} "${OBJECTDIR}/ADAS1000.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Communication.o: Communication.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Communication.o.d 
	@${RM} ${OBJECTDIR}/Communication.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Communication.o   Communication.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Communication.o 
	@${FIXDEPS} "${OBJECTDIR}/Communication.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Lcd.o: Lcd.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Lcd.o.d 
	@${RM} ${OBJECTDIR}/Lcd.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Lcd.o   Lcd.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Lcd.o 
	@${FIXDEPS} "${OBJECTDIR}/Lcd.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/main.o: main.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/main.o.d 
	@${RM} ${OBJECTDIR}/main.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/main.o   main.c 
	@${DEP_GEN} -d ${OBJECTDIR}/main.o 
	@${FIXDEPS} "${OBJECTDIR}/main.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/178502183/Serial.o: ../Matts_.X/Serial.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/178502183" 
	@${RM} ${OBJECTDIR}/_ext/178502183/Serial.o.d 
	@${RM} ${OBJECTDIR}/_ext/178502183/Serial.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/178502183/Serial.o   ../Matts_.X/Serial.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/178502183/Serial.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/178502183/Serial.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/_ext/178502183/RN.o: ../Matts_.X/RN.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}/_ext/178502183" 
	@${RM} ${OBJECTDIR}/_ext/178502183/RN.o.d 
	@${RM} ${OBJECTDIR}/_ext/178502183/RN.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/_ext/178502183/RN.o   ../Matts_.X/RN.c 
	@${DEP_GEN} -d ${OBJECTDIR}/_ext/178502183/RN.o 
	@${FIXDEPS} "${OBJECTDIR}/_ext/178502183/RN.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/mainbrain.o: mainbrain.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/mainbrain.o.d 
	@${RM} ${OBJECTDIR}/mainbrain.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/mainbrain.o   mainbrain.c 
	@${DEP_GEN} -d ${OBJECTDIR}/mainbrain.o 
	@${FIXDEPS} "${OBJECTDIR}/mainbrain.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
${OBJECTDIR}/Pacing.o: Pacing.c  nbproject/Makefile-${CND_CONF}.mk
	@${MKDIR} "${OBJECTDIR}" 
	@${RM} ${OBJECTDIR}/Pacing.o.d 
	@${RM} ${OBJECTDIR}/Pacing.o 
	${MP_CC} $(MP_EXTRA_CC_PRE) -p$(MP_PROCESSOR_OPTION) --verbose -ms -oa-  -I ${MP_CC_DIR}\\..\\h  -fo ${OBJECTDIR}/Pacing.o   Pacing.c 
	@${DEP_GEN} -d ${OBJECTDIR}/Pacing.o 
	@${FIXDEPS} "${OBJECTDIR}/Pacing.o.d" $(SILENT) -rsi ${MP_CC_DIR}../ -c18 
	
endif

# ------------------------------------------------------------------------------------
# Rules for buildStep: link
ifeq ($(TYPE_IMAGE), DEBUG_RUN)
dist/${CND_CONF}/${IMAGE_TYPE}/ComboTrial.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk    
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w -x -u_DEBUG -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -z__MPLAB_DEBUG=1 -z__MPLAB_DEBUGGER_PK3=1 $(MP_LINKER_DEBUG_OPTION) -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/ComboTrial.${IMAGE_TYPE}.${OUTPUT_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
else
dist/${CND_CONF}/${IMAGE_TYPE}/ComboTrial.${IMAGE_TYPE}.${OUTPUT_SUFFIX}: ${OBJECTFILES}  nbproject/Makefile-${CND_CONF}.mk   
	@${MKDIR} dist/${CND_CONF}/${IMAGE_TYPE} 
	${MP_LD} $(MP_EXTRA_LD_PRE)   -p$(MP_PROCESSOR_OPTION_LD)  -w  -m"${DISTDIR}/${PROJECTNAME}.${IMAGE_TYPE}.map"  -z__MPLAB_BUILD=1  -u_CRUNTIME -l ${MP_CC_DIR}\\..\\lib  -o dist/${CND_CONF}/${IMAGE_TYPE}/ComboTrial.${IMAGE_TYPE}.${DEBUGGABLE_SUFFIX}  ${OBJECTFILES_QUOTED_IF_SPACED}   
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
