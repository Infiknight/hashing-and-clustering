#
# Generated Makefile - do not edit!
#
# Edit the Makefile in the project folder instead (../Makefile). Each target
# has a -pre and a -post target defined where you can add customized code.
#
# This makefile implements configuration specific macros and targets.


# Environment
MKDIR=mkdir
CP=cp
GREP=grep
NM=nm
CCADMIN=CCadmin
RANLIB=ranlib
CC=gcc
CCC=g++
CXX=g++
FC=gfortran
AS=as

# Macros
CND_PLATFORM=MinGW-Windows
CND_DLIB_EXT=dll
CND_CONF=Debug
CND_DISTDIR=dist
CND_BUILDDIR=build

# Include project Makefile
include Makefile

# Object Directory
OBJECTDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}

# Object Files
OBJECTFILES= \
	${OBJECTDIR}/LSH.o \
	${OBJECTDIR}/LSH_structs.o \
	${OBJECTDIR}/bucket.o \
	${OBJECTDIR}/compare.o \
	${OBJECTDIR}/distance_matrix.o \
	${OBJECTDIR}/distance_matrix_hash_funcs.o \
	${OBJECTDIR}/distance_matrix_hash_table.o \
	${OBJECTDIR}/distance_matrix_parser.o \
	${OBJECTDIR}/distance_matrix_search.o \
	${OBJECTDIR}/distance_matrix_specialized_tools.o \
	${OBJECTDIR}/euclidean.o \
	${OBJECTDIR}/euclidean_hash_funcs.o \
	${OBJECTDIR}/euclidean_hash_table.o \
	${OBJECTDIR}/euclidean_parser.o \
	${OBJECTDIR}/euclidean_search.o \
	${OBJECTDIR}/euclidean_specialized_tools.o \
	${OBJECTDIR}/general_distance_matrix.o \
	${OBJECTDIR}/hamming.o \
	${OBJECTDIR}/initialize.o \
	${OBJECTDIR}/list.o \
	${OBJECTDIR}/main.o \
	${OBJECTDIR}/probability_distr.o \
	${OBJECTDIR}/reverse_assignment.o \
	${OBJECTDIR}/vector.o


# C Compiler Flags
CFLAGS=

# CC Compiler Flags
CCFLAGS=
CXXFLAGS=

# Fortran Compiler Flags
FFLAGS=

# Assembler Flags
ASFLAGS=

# Link Libraries and Options
LDLIBSOPTIONS=

# Build Targets
.build-conf: ${BUILD_SUBPROJECTS}
	"${MAKE}"  -f nbproject/Makefile-${CND_CONF}.mk ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/1h_anaptu3hs.exe

${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/1h_anaptu3hs.exe: ${OBJECTFILES}
	${MKDIR} -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}
	${LINK.c} -o ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/1h_anaptu3hs ${OBJECTFILES} ${LDLIBSOPTIONS}

${OBJECTDIR}/LSH.o: LSH.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSH.o LSH.c

${OBJECTDIR}/LSH_structs.o: LSH_structs.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/LSH_structs.o LSH_structs.c

${OBJECTDIR}/bucket.o: bucket.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/bucket.o bucket.c

${OBJECTDIR}/compare.o: compare.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/compare.o compare.c

${OBJECTDIR}/distance_matrix.o: distance_matrix.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distance_matrix.o distance_matrix.c

${OBJECTDIR}/distance_matrix_hash_funcs.o: distance_matrix_hash_funcs.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distance_matrix_hash_funcs.o distance_matrix_hash_funcs.c

${OBJECTDIR}/distance_matrix_hash_table.o: distance_matrix_hash_table.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distance_matrix_hash_table.o distance_matrix_hash_table.c

${OBJECTDIR}/distance_matrix_parser.o: distance_matrix_parser.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distance_matrix_parser.o distance_matrix_parser.c

${OBJECTDIR}/distance_matrix_search.o: distance_matrix_search.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distance_matrix_search.o distance_matrix_search.c

${OBJECTDIR}/distance_matrix_specialized_tools.o: distance_matrix_specialized_tools.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/distance_matrix_specialized_tools.o distance_matrix_specialized_tools.c

${OBJECTDIR}/euclidean.o: euclidean.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/euclidean.o euclidean.c

${OBJECTDIR}/euclidean_hash_funcs.o: euclidean_hash_funcs.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/euclidean_hash_funcs.o euclidean_hash_funcs.c

${OBJECTDIR}/euclidean_hash_table.o: euclidean_hash_table.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/euclidean_hash_table.o euclidean_hash_table.c

${OBJECTDIR}/euclidean_parser.o: euclidean_parser.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/euclidean_parser.o euclidean_parser.c

${OBJECTDIR}/euclidean_search.o: euclidean_search.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/euclidean_search.o euclidean_search.c

${OBJECTDIR}/euclidean_specialized_tools.o: euclidean_specialized_tools.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/euclidean_specialized_tools.o euclidean_specialized_tools.c

${OBJECTDIR}/general_distance_matrix.o: general_distance_matrix.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/general_distance_matrix.o general_distance_matrix.c

${OBJECTDIR}/hamming.o: hamming.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/hamming.o hamming.c

${OBJECTDIR}/initialize.o: initialize.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/initialize.o initialize.c

${OBJECTDIR}/list.o: list.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/list.o list.c

${OBJECTDIR}/main.o: main.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/main.o main.c

${OBJECTDIR}/probability_distr.o: probability_distr.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/probability_distr.o probability_distr.c

${OBJECTDIR}/reverse_assignment.o: reverse_assignment.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/reverse_assignment.o reverse_assignment.c

${OBJECTDIR}/vector.o: vector.c 
	${MKDIR} -p ${OBJECTDIR}
	${RM} "$@.d"
	$(COMPILE.c) -g -MMD -MP -MF "$@.d" -o ${OBJECTDIR}/vector.o vector.c

# Subprojects
.build-subprojects:

# Clean Targets
.clean-conf: ${CLEAN_SUBPROJECTS}
	${RM} -r ${CND_BUILDDIR}/${CND_CONF}
	${RM} ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/1h_anaptu3hs.exe

# Subprojects
.clean-subprojects:

# Enable dependency checking
.dep.inc: .depcheck-impl

include .dep.inc
