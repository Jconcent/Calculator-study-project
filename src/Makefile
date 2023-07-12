SRC_MODEL=model/RpnCalculator.cc model/EquationToRpnTransformer.cc
SRC_CONTROLLER=controller/CalculationController.cc
MAIN_CLASS=main.cc
LNG_STD=gnu++17
EXECUTABLE_NAME=calculator

all:
	g++ -std=${LNG_STD} ${MAIN_CLASS} ${SRC_MODEL} ${SRC_CONTROLLER} -o ${EXECUTABLE_NAME}

fclean:
	rm ${EXECUTABLE_NAME}