################################################################################
# Variable definitions
################################################################################

# Executable names
PROJECT = weatherReport

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++14
CXXFLAGS= ${CXXVERSION} -g

# Directories
SRC_DIR = src
SRC_INCLUDE = include
INCLUDE = -I .
OBJ_DIR = obj

# Tool variables
STATIC_ANALYSIS = cppcheck
STYLE_CHECK = cpplint

################################################################################
# Targets
################################################################################

# Default goal
.DEFAULT_GOAL := compileProject

################################################################################
# Clean-up targets
################################################################################
.PHONY: clean-exec
clean-exec:
	rm -rf ${PROJECT} ${PROJECT}.exe

.PHONY: clean-obj
clean-obj:
	rm -rf ${SRC}/*.o

.PHONY: clean-temp
clean-temp:
	rm -rf *~ \#* .\#* \
	${SRC_DIR}/*~ ${SRC_DIR}/\#* ${SRC_DIR}/.\#* \
	${SRC_INCLUDE}/*~ ${SRC_INCLUDE}/\#* ${SRC_INCLUDE}/.\#*	

.PHONY: clean
clean: clean-exec clean-obj clean-temp

################################################################################
# Compilaton targets
################################################################################

# default rule for compiling .cc to .o
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# Compilation targets
# compilation for making the project
# using the files in include, src, and src/project
${PROJECT}: ${SRC_DIR} clean-exec
	${CXX} ${CXXVERSION} -o ${PROJECT} ${INCLUDE} ${SRC_DIR}/*.cpp ${OBJ_DIR}/*.o

################################################################################
# Test targets
################################################################################

# To perform all tests
all: static style memcheck

# To perform the memory checks
memcheck: ${PROJECT}
	valgrind --tool=memcheck --leak-check=yes --error-exitcode=1 ./${PROJECT}

# To perform the static check 
static: ${SRC_DIR} ${SRC_INCLUDE}
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} \
	${SRC_INCLUDE} --suppress=missingInclude --error-exitcode=1

# To perform the style check
style: ${SRC_DIR} ${SRC_INCLUDE}
	${STYLE_CHECK} ${SRC_DIR}/* ${SRC_INCLUDE}/*	

################################################################################
# Revision History
################################################################################
# Updated: 2023-12-15 Nicole Wilson <n.wilson@uleth.ca>
#  Create a template for the CPSC2720 Card Game Minor Project
################################################################################
# Updated: 2022-12-15 Nicole Wilson <n.wilson@uleth.ca>
#  Removed all references to OS as the pipelines are now running on Ubuntu
################################################################################
# Updated: 2022-10-19 Dr. J. Anvik <john.anvik@uleth.ca>
#  Changed the static command to make the pipeline fail on exit with errors.
################################################################################
# Updated: 2022-09-11 Nicole Wilson <n.wilson@uleth.ca>
#  Added reference to OS in setting of STYLE_CHECK.
#  This is a temporary measure until the pipelines are running on Ubuntu
################################################################################
