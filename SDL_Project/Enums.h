#pragma once

enum class States {
	Splashscreen,
	MainMenu,
	Game,
	Credits,
	End,
	Language
};

enum class TileTypes {
	Empty,
	Wall,
	Player,
	Bomb
};

enum class TextureName {
	Background,
	Wall,
	Player
};

enum class Levels {
	Tutorial,
	Level1,
	Level2,
	Level3,
	Level4
};

enum class Language {
	German,
	English,
	Francais,
	Letzebuergesch,
	noLang
};