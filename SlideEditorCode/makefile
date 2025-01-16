# Compiler and flags
CXX = g++
CXXFLAGS = -Wall -std=c++20 -g

# Project directories
SRC_DIR = .
CLI_DIR = $(SRC_DIR)/CLI
ENUMS_DIR = $(SRC_DIR)/Enums
MODELS_DIR = $(SRC_DIR)/Models
ACTIONS_DIR = $(SRC_DIR)/Actions

# Source files
SRCS = $(CLI_DIR)/Command.cpp \
       $(CLI_DIR)/Parser.cpp \
       $(CLI_DIR)/SemanticAnalyzer.cpp \
       $(CLI_DIR)/SyntaxAnalyzer.cpp \
       $(CLI_DIR)/Tokenizer.cpp \
       $(MODELS_DIR)/Text.cpp \
       $(MODELS_DIR)/Item.cpp \
       $(MODELS_DIR)/Presentation.cpp \
       $(MODELS_DIR)/Slide.cpp \
       $(ACTIONS_DIR)/AddSlideAction.cpp \
       $(ACTIONS_DIR)/NextPrevSlidesAction.cpp \
       $(ACTIONS_DIR)/RemoveSlideAction.cpp \
       $(ACTIONS_DIR)/AddItemAction.cpp \
       $(ACTIONS_DIR)/RemoveItemAction.cpp \
       $(ACTIONS_DIR)/MoveItemAction.cpp \
       $(ACTIONS_DIR)/ChangeSizeAction.cpp \
       $(ACTIONS_DIR)/MoveSlideAction.cpp \
       $(SRC_DIR)/Controller.cpp \
       $(SRC_DIR)/Editor.cpp \
       $(SRC_DIR)/main.cpp

# Header files (included for completeness)
HDRS = $(CLI_DIR)/Command.hpp \
       $(CLI_DIR)/Parser.hpp \
       $(CLI_DIR)/SemanticAnalyzer.hpp \
       $(CLI_DIR)/SyntaxAnalyzer.hpp \
       $(CLI_DIR)/Tokenizer.hpp \
       $(ENUMS_DIR)/AlignTypeEnum.hpp \
       $(ENUMS_DIR)/ItemTypeEnum.hpp \
       $(ENUMS_DIR)/ShapeTypeEnum.hpp \
       $(MODELS_DIR)/Text.hpp \
       $(MODELS_DIR)/Item.hpp \
       $(MODELS_DIR)/Presentation.hpp \
       $(MODELS_DIR)/Slide.hpp \
       $(ACTIONS_DIR)/AddSlideAction.hpp \
       $(ACTIONS_DIR)/NextPrevSlidesAction.hpp \
       $(ACTIONS_DIR)/RemoveSlideAction.hpp \
       $(ACTIONS_DIR)/AddItemAction.hpp \
       $(ACTIONS_DIR)/RemoveItemAction.hpp \
       $(ACTIONS_DIR)/MoveItemAction.hpp \
       $(ACTIONS_DIR)/ChangeSizeAction.hpp \
       $(ACTIONS_DIR)/MoveSlideAction.hpp \
       $(ACTIONS_DIR)/IAction.hpp \
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
