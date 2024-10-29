# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++20

# Project directories
SRC_DIR = .
CLI_DIR = $(SRC_DIR)/CLI
ENUMS_DIR = $(SRC_DIR)/Enums
MODELS_DIR = $(SRC_DIR)/Models

# Source files
SRCS = $(CLI_DIR)/Command.cpp \
       $(CLI_DIR)/Parser.cpp \
       $(CLI_DIR)/SemanticAnalyzer.cpp \
       $(CLI_DIR)/SyntaxAnalyzer.cpp \
       $(CLI_DIR)/Tokenizer.cpp \
       $(MODELS_DIR)/Item.cpp \
       $(MODELS_DIR)/Presentation.cpp \
       $(MODELS_DIR)/Slide.cpp \
       $(SRC_DIR)/Controller.cpp \
       $(SRC_DIR)/Editor.cpp

# Header files (included for completeness)
HDRS = $(CLI_DIR)/Command.hpp \
       $(CLI_DIR)/Parser.hpp \
       $(CLI_DIR)/SemanticAnalyzer.hpp \
       $(CLI_DIR)/SyntaxAnalyzer.hpp \
       $(CLI_DIR)/Tokenizer.hpp \
       $(ENUMS_DIR)/AlignTypeEnum.hpp \
       $(ENUMS_DIR)/ItemTypeEnum.hpp \
       $(ENUMS_DIR)/ShapeTypeEnum.hpp \
       $(MODELS_DIR)/Item.hpp \
       $(MODELS_DIR)/Presentation.hpp \
       $(MODELS_DIR)/Slide.hpp \
       $(SRC_DIR)/Controller.hpp \
       $(SRC_DIR)/Editor.hpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Target executable
TARGET = slide_editor

# Default target
all: $(TARGET)

# Build target
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile source files into object files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)
