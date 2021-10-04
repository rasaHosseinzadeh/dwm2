/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 1;        /* border pixel of windows */
static const unsigned int gappx     = 8;       /* gap pixel between windows */
static const unsigned int snap      = 32;       /* snap pixel */
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { 
    "Hack Nerd Font:size=14:antialias=true:autohint=true",
};
static const char dmenufont[]       =  "Hack Nerd Font:size=14:antialias=true:autohint=true";
static char normbgcolor[]           = "#282a36";
static char normbordercolor[]       = "#282a36";
static char normfgcolor[]           = "#d7d7d7";
static char selbordercolor[]        = "#88527F";
static char selbgcolor[]            = "#88527F";
static char selfgcolor[]            = "#d7d7d7";
static char lightbluecolor[]        = "#B1DDF1";
static char grapecolor[]            = "#9F87AF";

static const unsigned int baralpha = 0xf2;
static const unsigned int borderalpha = OPAQUE;
static const char *colors[][3] = {
       /*               fg           bg           border   */
       [SchemeNorm]  =   { normfgcolor, normbgcolor, normbordercolor },
       [SchemeSel]   =   { selfgcolor,  selbgcolor,  selbordercolor  },
	   [SchemeWarn]  =	 { lightbluecolor, normbgcolor, normbordercolor },
	   [SchemeUrgent]=	 { grapecolor, normbgcolor, normbordercolor },
};
static const unsigned int alphas[][3]      = {
	/*               fg      bg        border     */
	[SchemeNorm]  = { OPAQUE, baralpha, borderalpha },
	[SchemeSel]   = { OPAQUE, baralpha, borderalpha },
	[SchemeWarn]  =	{ OPAQUE, baralpha, borderalpha },
	[SchemeUrgent]=	{ OPAQUE, baralpha, borderalpha },
};


/* tagging */
static const char *tags[] = { "1", "2", "3", "4", "5", "6", "7", "8", "9" };
static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance           title       tags mask       isfloating     monitor */
	{ "mpv",         NULL,           NULL,       0,                   0,           -1,  },
	{ "dmenu",       NULL,           NULL,       0,                   1,           -1,  },
	{ NULL,          "sxiv",         NULL,       0,                   1,           -1,  },
	{ NULL,          NULL,           "sxiv",     0,                   1,           -1,  },
	{ NULL,          "connman-gtk",  NULL, 	     0,                   1,           -1,  },
	{ NULL,          "dict",         NULL,       0,                   1,           -1,  },
	{ NULL,          "spnotes",      NULL, 	     0,                   1,           -1,  },
	{ NULL,          "spmusic",      NULL, 	     0,                   1,           -1,  },
	{ NULL,          "pavucontrol",  NULL, 	     0,                   1,           -1,  },
	{ NULL,          "keepassxc",    NULL, 	     0,                   1,           -1,  },
};

#define TERMINAL "st"

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */
static const int lockfullscreen = 0; /* 1 will force focus on the fullscreen window */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* commands */
//static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-i", "-l", "10", NULL };

static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_b,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_d,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_p,      zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,                       XK_q,      killclient,     {0} },
	{ MODKEY,                       XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY,                       XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY,                       XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
	TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
};

/* button definitions */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin         ,MODKEY|ShiftMask,Button1,       resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
