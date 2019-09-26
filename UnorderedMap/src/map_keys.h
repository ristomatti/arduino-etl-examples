#include <Arduino.h>
#include <etl/cstring.h>

const char* keys[] = {
    "abandon", "absence", "absent",  "absorb",  "abuse",   "account", "acquit",  "action",
    "active",  "add",     "adjust",  "admire",  "adult",   "advance", "adviser", "agency",
    "agile",   "aid",     "air",     "alarm",   "alcohol", "alive",   "allow",   "amber",
    "ample",   "analyst", "annual",  "ant",     "appeal",  "apple",   "appoint", "area",
};

// const char* keys[] = {
//     "abandon", "absence", "absent",  "absorb",  "abuse",   "account", "acquit",  "action",
//     "active",  "add",     "adjust",  "admire",  "adult",   "advance", "adviser", "agency",
//     "agile",   "aid",     "air",     "alarm",   "alcohol", "alive",   "allow",   "amber",
//     "ample",   "analyst", "annual",  "ant",     "appeal",  "apple",   "appoint", "area",
//     "arrow",   "artist",  "aspect",  "assault", "asset",   "attack",  "auditor", "aware",
//     "baby",    "bacon",   "bait",    "bake",    "balance", "ball",    "ballot",  "banana",
//     "banish",  "bare",    "bargain", "bark",    "barrel",  "base",    "basin",   "bat",
//     "bathtub", "battery", "beam",    "beard",   "bed",     "bedroom", "bee",     "beg",
//     "belong",  "bench",   "benefit", "betray",  "bike",    "bill",    "bind",    "biology",
//     "bishop",  "blade",   "bland",   "blast",   "bleed",   "bless",   "blind",   "blonde",
//     "abandon", "absence", "absent",  "absorb",  "abuse",   "account", "acquit",  "action",
//     "active",  "add",     "adjust",  "admire",  "adult",   "advance", "adviser", "agency",
//     "agile",   "aid",     "air",     "alarm"
// };

// const char* keys[] PROGMEM = {
//     "abandon", "absence", "absent",  "absorb",  "abuse",   "account", "acquit",  "action",
//     "active",  "add",     "adjust",  "admire",  "adult",   "advance", "adviser", "agency",
//     "agile",   "aid",     "air",     "alarm",   "alcohol", "alive",   "allow",   "amber",
//     "ample",   "analyst", "annual",  "ant",     "appeal",  "apple",   "appoint", "area",
//     "arrow",   "artist",  "aspect",  "assault", "asset",   "attack",  "auditor", "aware",
//     "baby",    "bacon",   "bait",    "bake",    "balance", "ball",    "ballot",  "banana",
//     "banish",  "bare",    "bargain", "bark",    "barrel",  "base",    "basin",   "bat",
//     "bathtub", "battery", "beam",    "beard",   "bed",     "bedroom", "bee",     "beg",
//     "belong",  "bench",   "benefit", "betray",  "bike",    "bill",    "bind",    "biology",
//     "bishop",  "blade",   "bland",   "blast",   "bleed",   "bless",   "blind",   "blonde",
//     "bloody",  "board",   "boat",    "bold",    "bomber",  "book",    "boot",    "borrow",
//     "bother",  "bottom",  "bounce",  "bow",     "bowel",   "boy",     "bracket", "brave",
//     "bread",   "breathe", "breed",   "breeze",  "bride",   "bridge",  "brink",   "broken",
//     "brown",   "brush",   "bubble",  "bucket",  "buffet",  "build",   "bulb",    "burial",
//     "burn",    "bus",     "cabin",   "cable",   "cafe",    "calm",    "calorie", "camera",
//     "camp",    "candle",  "cane",    "capital", "capture", "car",     "carbon",  "card",
//     "career",  "carrot",  "carry",   "cart",    "case",    "cast",    "catch",   "cave",
//     "cellar",  "census",  "century", "cereal",  "certain", "chalk",   "channel", "chaos",
//     "chapter", "charity", "charm",   "charter", "cheap",   "cheat",   "cheese",  "chest",
//     "chief",   "chimney", "choice",  "choke",   "chorus",  "church",  "cinema",  "circle",
//     "citizen", "claim",   "clarify", "class",   "clean",   "clerk",   "climb",   "clock",
//     "close",   "coach",   "coast",   "coin",    "cold",    "collect", "colony",  "color",
//     "comedy",  "comfort", "comment", "compact", "company", "compete", "concede", "concern",
//     "contact", "contain", "context", "convert", "convict", "cook",    "cope",    "copper",
//     "core",    "corner",  "costume", "cottage", "count",   "counter", "courage", "course",
//     "court",   "cousin",  "cower",   "crack",   "crash",   "crevice", "crew",    "crime",
//     "cross",   "cruelty", "crusade", "cry",     "crystal", "cup",     "curl",    "curtain",
//     "custody", "damage",  "damn",    "dance",   "danger",  "dare",    "dash",    "date",
//     "dead",    "deal",    "dealer",  "death",   "debate",  "debt",    "debut",   "decide",
//     "decline", "deer",    "deficit", "define",  "denial",  "density", "depart",  "deport",
//     "deposit", "deprive", "deputy",  "descent", "desert",  "deserve", "desire",  "desk",
//     "despair", "despise", "detail",  "deter",   "devote",  "dictate", "die",     "dilemma",
//     "dip",     "dirty",   "disco",   "dish",    "dismiss", "display", "distant", "dive",
//     "doctor",  "dog",     "doll",    "dome",    "door",    "double",  "doubt",   "dough",
//     "draft",   "drain",   "drawing", "dress",   "dribble", "drill",   "driver",  "drop",
//     "drum",    "dry",     "duke",    "dull",    "duty",    "dynamic", "eagle",   "ear",
//     "east",    "easy",    "eat",     "efflux",  "effort",  "egg",     "ego",     "eject",
//     "elect",   "elegant", "element", "embox",   "embrace", "embryo",  "emotion", "end",
//     "energy",  "enfix",   "engine",  "enlarge", "ensure",  "entry",   "era",     "error",
//     "estate",  "ethics",  "ethnic",  "even",    "evoke",   "ex",      "exclude", "exit",
//     "exotic",  "expand",  "expect",  "explain", "express", "extinct", "extreme", "eyebrow",
//     "face",    "factor",  "fail",    "faint",   "fairy",   "faith",   "false",   "fame",
//     "family",  "fantasy", "fast",    "fault",   "fax",     "fear",    "feature", "feel",
//     "feign",   "ferry",   "fibre",   "fiction", "field",   "fight",   "fill",    "find",
//     "fine",    "finger",  "finish",  "firm",    "first",   "fit",     "fixture", "flash",
//     "flawed",  "fleet",   "flesh",   "flex",    "fling",   "float",   "flock",   "floor",
//     "flow",    "flu",     "fold",    "follow",  "fool",    "foot",    "forbid",  "forest",
//     "forget",  "fork",    "formula", "forum",   "forward", "fossil",  "foster",  "frank",
//     "freckle", "freeze",  "full",    "fur",     "future",  "galaxy",  "gallery", "game",
//     "gap",     "garage",  "garlic",  "gas",     "gasp",    "gear",    "gene",    "genuine",
//     "gesture", "get",     "give",    "glare",   "glide",   "global",  "gloom",   "glow",
//     "goal",    "good",    "gown",    "gradual", "grant",   "grass",   "grave",   "graze",
//     "great",   "green",   "grimace", "ground",  "grudge",  "guard",   "guest",   "habitat",
//     "hall",    "hallway", "halt",    "hand",    "hard",    "harmony", "harsh",   "harvest",
//     "hate",    "haunt",   "have",    "heart",   "heaven",  "heavy",   "heir",    "hell",
//     "helmet",  "hen",     "herb",    "herd",    "history", "hit",     "holiday", "home",
//     "honor",   "hope",    "horizon", "horror",  "horse",   "hostile", "hot",     "hotdog",
//     "housing", "hover",   "hunting", "hut",     "ignite",  "ignore",  "image",   "immune",
//     "impress", "improve", "impulse", "inch",    "index",   "indoor",  "infect",  "inflate",
//     "initial", "inject",  "inquiry", "insight", "insist",  "iron",    "irony",   "issue",
//     "item",    "jealous", "jelly",   "jet",     "jockey",  "journal", "jury",    "keep",
//     "kettle",  "kick",    "kid",     "kidnap",  "killer",  "king",    "knit",    "knot",
//     "know",    "labour",  "lace",    "lake",    "lamb",    "lamp",    "land",    "large",
//     "late",    "laundry", "law",     "layout",  "leaf",    "leak",    "learn",   "left",
//     "leg",     "level",   "liberal", "licence", "lick",    "like",    "lily",    "limit",
//     "lineage", "lip",     "list",    "listen",  "liver",   "load",    "loan",    "long",
//     "loose",   "loot",    "loss",    "lost",    "love",    "lover",   "lump",    "maid",
//     "major",   "make",    "makeup",  "man",     "manage",  "manager", "manual",  "margin",
//     "marine",  "mask",    "master",  "match",   "maximum", "mayor",   "maze",    "meadow",
//     "meal",    "meaning", "medium",  "meet",    "member",  "menu",    "mercy",   "middle",
//     "mild",    "mill",    "mind",    "minor",   "miracle", "mirror",  "misery",  "mislead",
//     "miss",    "missile", "mix",     "mixture", "mobile",  "module",  "mold",    "mole",
//     "month",   "mood",    "morale",  "morsel",  "mosaic",  "mother",  "motif",   "mouth",
//     "move",    "mud",     "mug",     "muggy",   "murder",  "mutter",  "mystery", "nail",
//     "name",    "narrow",  "native",  "navy",    "needle",  "nervous", "nest",    "new",
//     "node",    "north",   "note",    "nuance",  "nuclear", "number",  "nun",     "nut",
//     "offer",   "orange",  "organ",   "orgy",    "other",   "outer",   "outfit",  "outlet",
//     "outside", "oven",    "overall", "owl",     "packet",  "pain",    "pair",    "palace",
//     "palm",    "panel",   "panic",   "paradox", "pardon",  "park",    "partner", "pass",
//     "passion", "path",    "patrol",  "peanut",  "peasant", "penalty", "perfect", "perfume",
//     "persist", "petty",   "piano",   "picture", "pie",     "piece",   "pier",    "pill",
//     "pioneer", "pipe",    "pit",     "plan",    "planet",  "plant",   "plaster", "plastic",
//     "play",    "player",  "please",  "pledge",  "plot",    "pluck",   "pocket",  "poem",
//     "poetry",  "point",   "poison",  "pony",    "porter",  "post",    "posture", "pot",
//     "pound",   "pour",    "pray",    "prefer",  "premium", "prince",  "print",   "prison",
//     "privacy", "problem", "process", "produce", "profile", "profit",  "project", "proof",
//     "proper",  "protect", "protest", "proud",   "provide", "provoke", "pump",    "pumpkin",
//     "punch",   "punish",  "pupil",   "pure",    "purpose", "pursuit", "put",     "pyramid",
//     "quality", "queen",   "quest",   "queue",   "quit",    "rabbit",  "race",    "rack",
//     "radio",   "raid",    "railcar", "raise",   "rally",   "random",  "range",   "rate",
//     "raw",     "reader",  "realism", "realize", "rear",    "recover", "red",     "referee",
//     "reflect", "regular", "reign",   "relate",  "related", "relief",  "relieve", "remark",
//     "repeat",  "rescue",  "reserve", "resign",  "respect", "rest",    "retain",  "retired",
//     "return",  "reverse", "review",  "revive",  "revoke",  "reward",  "rhythm",  "rib",
//     "rice",    "ridge",   "right",   "ring",    "riot",    "rise",    "ritual",  "rock",
//     "room",    "rotate",  "round",   "royalty", "rubbish", "rugby",   "rule",    "run",
//     "runner",  "rush",    "safari",  "salmon",  "salon",   "sausage", "scene",   "school",
//     "science", "second",  "section", "sector",  "secular", "secure",  "seed",    "seek",
//     "sell",    "session", "shaft",   "shake",   "shape",   "share",   "shatter", "shave",
//     "shed",    "sheep",   "sheet",   "shelf",   "shelter", "shift",   "shoot",   "shop",
//     "shorts",  "shot",    "shout",   "show",    "shrink",  "side",    "sigh",    "sin",
//     "singer",  "single",  "sip",     "sister",  "sit",     "skate",   "skip",    "sleeve",
//     "slide",   "slump",   "smell",   "smoke",   "snake",   "sniff",   "snuggle", "soap",
//     "sock",    "sofa",    "soil",    "solo",    "soul",    "soup",    "sour",    "source",
//     "sow",     "speaker", "speed",   "spend",   "sphere",  "spin",    "splurge", "sport",
//     "spray",   "squeeze", "stable",  "staff",   "stain",   "stamp",   "star",    "station",
//     "stay",    "steam",   "steel",   "steep",   "stem",    "steward", "stomach", "store",
//     "straw",   "stream",  "strong",  "studio",  "stuff",   "stun",    "style",   "suburb",
//     "suffer",  "sugar",   "suggest", "sunrise", "support", "surface", "surgeon", "swallow",
//     "sweat",   "sweet",   "swell",   "swop",    "sword",   "symptom", "system",  "table",
//     "talk",    "tank",    "tasty",   "tease",   "tenant",  "tender",  "tense",   "tent",
//     "term",    "terrace", "terrify", "test",    "texture", "thank",   "thanks",  "theft",
//     "theme",   "theory",  "thesis",  "thin",    "thirsty", "thread",  "throat",  "throw",
//     "tick",    "ticket",  "tight",   "tin",     "tip",     "tire",    "tissue",  "title",
//     "toast",   "ton",     "tongue",  "tool",    "topple",  "torture", "toss",    "total",
//     "touch",   "tough",   "tract",   "trade",   "trainer", "tray",    "treat",   "treaty",
//     "trench",  "trend",   "trick",   "trivial", "trouser", "truck",   "trunk",   "trustee",
//     "try",     "tumour",  "tune",    "turkey",  "turn",    "twist",   "twitch",  "unique",
//     "unit",    "unlike",  "update",  "urgency", "valid",   "valley",  "value",   "van",
//     "verdict", "veteran", "victory", "view",    "virgin",  "visit",   "vote",    "voter",
//     "voucher", "wage",    "waist",   "wait",    "walk",    "want",    "ward",    "waste",
//     "watch",   "water",   "wave",    "way",     "weave",   "wedding", "weed",    "weigh",
//     "welcome", "wheat",   "white",   "wife",    "will",    "wing",    "wire",    "word",
//     "work",    "world",   "worm",    "worry",   "worth",   "wound",   "wrap",    "wreck",
//     "wrestle", "wrong",   "X-ray",   "year",    "yearn",   "young",   "youth",   "zero"
// };