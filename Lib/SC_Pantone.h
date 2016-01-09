#ifndef HEADER_PANTONE
#define HEADER_PANTONE

//enum EPantone
//{
//	Pantone_Blanc = 1,
//	Pantone_Rouge,
//
//	Pantone_Bleu,
//	Pantone_Orange,
//
//	Pantone_Violet,
//	Pantone_Mauve,
//
//	Pantone_Vert,
//	Pantone_Jaune,
//
//	Pantone_Cyan,
//	Pantone_Noir,
//
//	Pantone_Gris,
//	Pantone_Rose,
//
//	Pantone_Indigo,
//	Pantone_OR,
//
//	Pantone_Argent,
//};

static const int g_iMaxColor = 19;

#define EPantone_Blanc			GfxColor( 255, 255, 255, 255 )
								
#define EPantone_Chair			GfxColor( 255, 150, 150, 255 )
#define EPantone_Rose			GfxColor( 255, 0, 255, 255 )
#define EPantone_Rouge			GfxColor( 255, 0, 0, 255 )
#define EPantone_Orange			GfxColor( 255, 130, 0, 255 )
#define EPantone_Jaune			GfxColor( 255, 255, 0, 255 )
#define EPantone_Mauve			GfxColor( 100, 0, 255, 255 )
#define EPantone_Violet			GfxColor( 160, 32, 240, 255 )
								
#define EPantone_Bleu			GfxColor( 0, 0, 255, 255 )
#define EPantone_BleuClair		GfxColor( 150, 150, 255, 255 )
#define EPantone_Cyan			GfxColor( 0, 255, 255, 255 )
#define EPantone_Vert			GfxColor( 0, 255, 0, 255 )
								
#define EPantone_Brun			GfxColor( 200, 100, 0, 255 )
								
#define EPantone_Noir			GfxColor( 0, 0, 0, 255 )
#define EPantone_Gris_Clair		GfxColor( 200, 200, 200, 255 )
#define EPantone_Gris			GfxColor( 150, 150, 150, 255 )
#define EPantone_Gris_Foncer	GfxColor( 100, 100, 100, 255 )

#define EPantone_MI_Blanc		GfxColor( 255, 255, 255, 125 )
#define EPantone_MI_Noir		GfxColor( 0, 0, 0, 125 )

static unsigned int g_iPantone[g_iMaxColor] = {
	EPantone_Brun,
	EPantone_Rose,
	EPantone_Rouge,
	EPantone_Orange,
	EPantone_Jaune, 
	EPantone_Mauve, 
	EPantone_Bleu, 
	EPantone_Violet,
	EPantone_BleuClair,
	EPantone_Cyan,
	EPantone_Vert, 
	EPantone_Blanc, 
	EPantone_Noir, 
	EPantone_Gris_Clair,
	EPantone_Chair,
	EPantone_Gris, 
	EPantone_Gris_Foncer, 
	EPantone_MI_Blanc, 
	EPantone_MI_Noir };

#endif
