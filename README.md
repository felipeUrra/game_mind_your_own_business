# Game — Mind Your Own Business

## Table of contents
- [About](#about)
- [Features](#features)
- [Project structure](#project-structure)
- [Getting started](#getting-started)
  - [Prerequisites](#prerequisites)
  - [Install](#install)
  - [Run](#run)
  - [Build](#build)
- [Configuration](#configuration)
- [Controls](#controls)
- [Testing](#testing)

## About
**Mind Your Own Business** is a game project. The goal of this repository is to provide the full source code and assets needed to run and build the game.

## Features
- Core gameplay loop
- Sound and visuals (assets in-repo)
- Configurable settings (difficulty/volume/etc.)

> Replace these bullets with the real features once you confirm the game’s mechanics.

## Project structure
> Update these paths to match what’s actually in the repo.

Common layouts you might have:
- `src/` — source code
- `assets/` — game art/audio/data
- `scenes/` — scenes/levels
- `docs/` — documentation
- `build/` or `dist/` — build output
- `scripts/` — helper scripts (build, tooling)

## Getting started

### Prerequisites
List the tools needed to run/build the project. Examples:
- Node.js `>= 18` (for web games)
- Python `>= 3.10` (for tooling)
- Godot `>= 4.x` / Unity `20xx.x` / Unreal `5.x` (for engine-based games)

### Install
Clone the repo:
```bash
git clone https://github.com/felipeUrra/game_mind_your_own_business.git
cd game_mind_your_own_business
```

If your project has dependencies, add one of the following (keep only what applies):

**Node / npm**
```bash
npm install
```

**Python**
```bash
python -m venv .venv
# macOS/Linux
source .venv/bin/activate
# Windows (PowerShell)
# .venv\Scripts\Activate.ps1
pip install -r requirements.txt
```

### Run
Add the run steps for your stack (keep only what applies):

**Node / dev server**
```bash
npm run dev
```

**Godot**
- Open the project in Godot (`project.godot`)
- Press **Play** (F5)

**Unity**
- Open the project in Unity Hub
- Open the main scene
- Press **Play**

### Build
Add build steps for your stack (keep only what applies):

**Node**
```bash
npm run build
```

**Godot**
- `Project` → `Export...` → choose preset → `Export Project`

**Unity**
- `File` → `Build Settings...` → `Build`

## Configuration
Document any environment variables or config files here.

Example:
- `config.json` — gameplay tuning values
- `.env` — runtime configuration (if applicable)

## Controls
Describe the controls (keyboard/mouse/controller). Example template:

- **Move:** WASD / Arrow keys
- **Interact:** E / Enter
- **Pause:** Esc

## Testing
If tests exist, document how to run them. Examples:

**Node**
```bash
npm test
```

**Python**
```bash
pytest -q
```
