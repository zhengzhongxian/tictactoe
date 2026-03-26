# Tic Tac Toe Game - OOP Final Project

A modern, feature-rich Tic Tac Toe game built with C++ Builder using object-oriented programming principles. This project demonstrates advanced GUI development, AI implementation, and game logic design.

## 🎮 Demo Video

[Watch the demo video](https://res.cloudinary.com/dnzzexe1d/video/upload/v1774549057/7259173882422_1_sboiuy.mp4)

## 🛠️ Technology Stack

- **Programming Language**: C++
- **Framework**: C++ Builder (FireMonkey - FMX)
- **IDE**: RAD Studio 11 (Embarcadero)
- **Platform**: Windows (Win32/Win64)
- **Project Type**: Visual FMX Application

## ✨ Features

### 🔐 User Authentication
- Secure login system with username and password validation
- Account credentials stored in `account_tictactoe.txt`
- Input validation and error handling
- Elegant login interface with visual effects

### 🎯 Game Modes
1. **Player vs Player**: Two human players take turns
2. **Player vs AI**: Single player against intelligent AI bot

### 🤖 AI Difficulty Levels
- **Easy Mode**: Random move selection
- **Normal Mode**: Strategic gameplay with win/block detection
- **Hard Mode**: Advanced AI using Minimax algorithm with alpha-beta pruning

### 🎨 User Interface
- Modern, responsive GUI design
- Smooth animations and visual effects
- Glow effects and color transitions
- Interactive buttons with hover states
- Real-time game status updates
- Background music and sound effects

### 🎵 Audio Features
- Background music during gameplay
- Sound effects for moves and game events
- Audio controls and management

## 🏗️ Architecture

### Object-Oriented Design
The project follows solid OOP principles with the following class structure:

#### Core Classes
- **`Game`**: Main game controller managing players and game flow
- **`Player`**: Base class for human players with symbol and turn management
- **`Robot`**: AI player class inheriting from Player with difficulty modes
- **`Board`**: Game board logic with win detection and state management

#### Key Components
- **`TForm_Game`**: Main form handling UI interactions and game events
- **`TInvalidForm`**: Error dialog for invalid login attempts

### Design Patterns
- **Inheritance**: Robot extends Player class
- **Composition**: Game class contains Player and Robot objects
- **Strategy Pattern**: Different AI difficulty implementations

## 🎮 Gameplay Features

### Game Flow
1. **Login**: Authenticate with username/password
2. **Mode Selection**: Choose between Player vs Player or Player vs AI
3. **Character Selection**: Pick X or O for each player
4. **Turn Order**: Set who goes first (Player 1, Player 2, or Random)
5. **Gameplay**: Interactive 3x3 grid with real-time updates
6. **Win Detection**: Automatic detection of wins, losses, and draws

### AI Intelligence
- **Easy**: Random valid moves
- **Normal**: 
  - Prioritizes winning moves
  - Blocks opponent's winning moves
  - Creates strategic opportunities
- **Hard**: 
  - Implements Minimax algorithm
  - Uses alpha-beta pruning for optimization
  - Provides challenging gameplay

## 📁 Project Structure

```
OOP_Final_Project/
├── OOP_XO.cbproj          # Main project file
├── OOP_XO.cpp             # Application entry point
├── Tic_Tac_Toe.h/.cpp     # Main form implementation
├── Tic_Tac_Toe.fmx        # Form design file
├── Game.h/.cpp            # Game logic class
├── Player.h/.cpp          # Player base class
├── Robot.h/.cpp           # AI player implementation
├── Board.h/.cpp           # Game board logic
├── Displayinvalid.h/.cpp  # Error dialog
├── account_tictactoe.txt  # User credentials
└── Win32/                 # Compiled binaries
```

## 🚀 Getting Started

### Prerequisites
- RAD Studio 11 or later
- Windows operating system
- C++ Builder with FireMonkey framework

### Installation
1. Clone or download the project
2. Open `OOP_XO.cbproj` in RAD Studio
3. Build the project (F9)
4. Run the application

### Default Login
- **Username**: `hien`
- **Password**: `123`

## 🎯 How to Play

1. **Login**: Enter your credentials
2. **Select Mode**: Choose Player vs Player or Player vs AI
3. **Choose Difficulty** (AI mode): Easy, Normal, or Hard
4. **Select Symbols**: Pick X or O for each player
5. **Set Turn Order**: Decide who goes first
6. **Play**: Click on empty cells to make moves
7. **Win**: Get three in a row (horizontal, vertical, or diagonal)

## 🔧 Technical Implementation

### Key Algorithms
- **Minimax Algorithm**: For hard AI difficulty
- **Alpha-Beta Pruning**: Optimization for AI decision making
- **Win Detection**: Efficient checking of all winning combinations
- **Game State Management**: Proper handling of turns and game flow

### UI Components
- Custom styled buttons and rectangles
- Animated transitions and effects
- Dynamic color changes and opacity
- Responsive layout design

## 🎨 Visual Features

- Gradient backgrounds and modern styling
- Smooth animations for transitions
- Interactive hover effects
- Color-coded player indicators
- Visual feedback for game states

## 📝 Future Enhancements

- Network multiplayer support
- Tournament mode
- Statistics tracking
- Custom themes and skins
- Mobile platform support
- Save/load game functionality

## 👥 Contributors

**Developer**: Trịnh Trung Hiển
**Student ID**: 48.01.104.041
**University**: Ho Chi Minh City University of Education (Đại học Sư phạm Thành phố Hồ Chí Minh)

This project was developed as an Object-Oriented Programming final project, demonstrating advanced C++ concepts and GUI development skills.

## 📄 License

This project is for educational purposes as part of an OOP course final project.
