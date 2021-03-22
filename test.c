/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   test.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: mvan-wij <mvan-wij@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/02/27 14:37:48 by mvan-wij      #+#    #+#                 */
/*   Updated: 2021/03/22 13:54:25 by mvan-wij      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include "lib/libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <math.h>
#define SKIP_REG

#define PRINTF_SINGLE(format) {\
	printf("ft_printf(%s):\n\"", format);\
	printf("\" (%i) <== expected\n", printf(format));\
	fflush(NULL);\
}

#define PRINTF(format, ...) {\
	printf("ft_printf(%s, %s):\n\"", format, #__VA_ARGS__);\
	printf("\" (%i) <== expected\n", printf(format, __VA_ARGS__));\
	fflush(NULL);\
}

// #define TEST(...) __VA_ARGS__
#define FT_PRINTF_SINGLE(format) {\
	PRINTF_SINGLE(format);\
	write(1, "\"", 1);\
	ft_printf(format, print_info);\
}

#define FT_PRINTF(format, ...) {\
	PRINTF(format, __VA_ARGS__);\
	write(1, "\"", 1);\
	ft_printf(format, __VA_ARGS__, print_info);\
}

#define PRINTF_SINGLE_NL(format) {\
	PRINTF_SINGLE(format);\
	write(1, "\n", 1);\
}

#define PRINTF_NL(format, ...) {\
	PRINTF(format, __VA_ARGS__);\
	write(1, "\n", 1);\
}

char	*pad_name(t_conv *conv)
{
	if (conv->e_pad_type == LEFT)
		return ("LEFT");
	if (conv->e_pad_type == RIGHT)
		return ("RIGHT");
	if (conv->e_pad_type == ZERO)
		return ("ZERO");
	return ("(UNKNOWN)");
}

char	*type_name(t_conv *conv)
{
	if (conv->e_type == UNSET)
		return ("UNSET");
	if (conv->e_type == PCT)
		return ("PCT");
	if (conv->e_type == CHAR)
		return ("CHAR");
	if (conv->e_type == STRING)
		return ("STRING");
	if (conv->e_type == INT)
		return ("INT");
	if (conv->e_type == UINT)
		return ("UINT");
	if (conv->e_type == HEX_LOW)
		return ("HEX_LOW");
	if (conv->e_type == HEX_CAP)
		return ("HEX_CAP");
	if (conv->e_type == PTR)
		return ("PTR");
	return ("(UNKNOWN)");
}

void	print_info(int len, t_conv *conv)
{
	(void)len;
	(void)conv;
	printf("\" (%i) <== got\n\n", len);
	/*printf("\
\" (%i) <== got\n\
fw: %i,\n\
p: %i,\n\
pad: %s,\n\
type: %s\n\n",
	len, conv->field_width, conv->precision, pad_name(conv),
	type_name(conv));*/
	fflush(NULL);
}

int	main(void)
{
	#ifndef SKIP_REG
	// regular tests
	FT_PRINTF("%c", 'a');
	FT_PRINTF("%i", 12);
	FT_PRINTF("%i", -12);
	FT_PRINTF("%p", (void *)84);
	FT_PRINTF("%p", (void *)-84);
	FT_PRINTF_SINGLE("%%");
	FT_PRINTF("%s", "hello");
	FT_PRINTF("%s", NULL);
	FT_PRINTF("%u", 932);
	FT_PRINTF("%u", -932);
	FT_PRINTF("%x", 7823);
	FT_PRINTF("%X", -7823);

	FT_PRINTF("%12c", 'a');
	FT_PRINTF("%12i", 12);
	FT_PRINTF("%12i", -12);
	FT_PRINTF("%12p", (void *)84);
	FT_PRINTF("%12p", (void *)-84);
	FT_PRINTF_SINGLE("%12%");
	FT_PRINTF("%12s", "hello");
	FT_PRINTF("%12s", NULL);
	FT_PRINTF("%12u", 932);
	FT_PRINTF("%12u", -932);
	FT_PRINTF("%12x", 7823);
	FT_PRINTF("%12X", -7823);

	FT_PRINTF("%012c", 'a');
	FT_PRINTF("%012i", 12);
	FT_PRINTF("%012i", -12);
	FT_PRINTF("%012p", (void *)84);
	FT_PRINTF("%012p", (void *)-84);
	FT_PRINTF_SINGLE("%012%");
	FT_PRINTF("%012s", "hello");
	FT_PRINTF("%012s", NULL);
	FT_PRINTF("%012u", 932);
	FT_PRINTF("%012u", -932);
	FT_PRINTF("%012x", 7823);
	FT_PRINTF("%012X", -7823);

	FT_PRINTF("%.12c", 'a');
	FT_PRINTF("%.12i", 12);
	FT_PRINTF("%.12i", -12);
	FT_PRINTF("%.12p", (void *)84);
	FT_PRINTF("%.12p", (void *)-84);
	FT_PRINTF_SINGLE("%.12%");
	FT_PRINTF("%.12s", "hello");
	FT_PRINTF("%.12s", NULL);
	FT_PRINTF("%.12u", 932);
	FT_PRINTF("%.12u", -932);
	FT_PRINTF("%.12x", 7823);
	FT_PRINTF("%.12X", -7823);

	FT_PRINTF("%12.6c", 'a');
	FT_PRINTF("%12.6i", 12);
	FT_PRINTF("%12.6i", -12);
	FT_PRINTF("%12.6p", (void *)84);
	FT_PRINTF("%12.6p", (void *)-84);
	FT_PRINTF_SINGLE("%12.6%");
	FT_PRINTF("%12.6s", "hello");
	FT_PRINTF("%12.6s", NULL);
	FT_PRINTF("%12.6u", 932);
	FT_PRINTF("%12.6u", -932);
	FT_PRINTF("%12.6x", 7823);
	FT_PRINTF("%12.6X", -7823);

	FT_PRINTF("%.c", 'a');
	FT_PRINTF("%.i", 12);
	FT_PRINTF("%.i", -12);
	FT_PRINTF("%.p", (void *)84);
	FT_PRINTF("%.p", (void *)-84);
	FT_PRINTF_SINGLE("%.%");
	FT_PRINTF("%.s", "hello");
	FT_PRINTF("%.s", NULL);
	FT_PRINTF("%.u", 932);
	FT_PRINTF("%.u", -932);
	FT_PRINTF("%.x", 7823);
	FT_PRINTF("%.X", -7823);

	FT_PRINTF("%012.2c", 'a');
	FT_PRINTF("%012.2i", 12);
	FT_PRINTF("%012.2i", -12);
	FT_PRINTF("%012.2p", (void *)84);
	FT_PRINTF("%012.2p", (void *)-84);
	FT_PRINTF_SINGLE("%012.2%");
	FT_PRINTF("%012.2s", "hello");
	FT_PRINTF("%012.2s", NULL);
	FT_PRINTF("%012.2u", 932);
	FT_PRINTF("%012.2u", -932);
	FT_PRINTF("%012.2x", 7823);
	FT_PRINTF("%012.2X", -7823);
	#else
	// FT_PRINTF("%s\n\n\n", "aiehfuakstchtbuyksebytiestuygfkuycguywfuasdmhasdduywabfmhgwgbdyiuAcgkussbCCKJHBC B,JAACH,JVDDILUHDGidhIULSCnbh<hwdjo'pae j[09jwh4l;gi=0s'jg-pojiw[w-34gkmnq3f[v-0  vjq3ntv=mLesenfantsnesententpastrestresbon1-aiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraiokt[k-q20oprjfgh09pjfhaw 90fha9w8efjhilaw98uf24[opawh5o291g25aw91fh92o5askj91b2floai19w k2hfh519loaw2ie5nfb192aei5b192izub1v92liuae66hfb9278iaeu19fh26oae192hvi616sene92r,g51v9i2esng29895aeib29giy59h 2eosj5g19g2ane621o9 9jao2erg 82enr6o9123jaeoi;rg192h3ioear2 n369er3gr6n5es6n4v5369aei4jr53oise9n5liu43ejs5rgl3es5hgoi93645bsr3969g45n69.3l45ojg3;54ozd9h57v9l369n7dz5liv57hb639,hzkdh5v369nk,45hzd3fbvj5j3knfv969l3bak4uch93654ilar69fj45v369il4D5Svm936n,kzs93dvjn9ldisunv45936lisudsu45nv369u9s45din369vl5szd9vnb4kidsz9bv23iuzs6db2v394iuzdr3n5vb6uis3sn6v4biowi-6w45v3h;o-4i65h3v-;oi5w.H4-v5lj.s4-6hdv53vo6-4kbS35LDi69bv-435iS6D4HBc35liu9s4b53c9iS4B53cv 4935sdbz9i4563abes 6945g3bs4569vb45k,h6SDdv453hk6dszb639vi5h4bdisz6y54vb369.kS54D36v9bb54k,sz6vb453hkzdf45uvb36945zdiluuv45b369jkz.45sdh369v45kjzs369df45vi369n45aer36fh45f369i4uewr45yffh6if45a9368szduhf45va9lwei3624sjhf3624ieu32jhf36c 23,6k m4jzdm3hfbc 43ki2.aekrus69");
	FT_PRINTF("%s\n\n\n", "Lesenfantsnesententpastrestresbon1-aiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraiokt[k-q20oprjfgh09pjfhaw 90fha9w8efjhilaw98uf24[opawh5o291g25aw91fh92o5askj91b2floai19w k2hfh519loaw2ie5nfb192aei5b192izub1v92liuae66hfb9278iaeu19fh26oae192hvi616sene92r,g51v9i2esng29895aeib29giy59h 2eosj5g19g2ane621o9 9jao2erg 82enr6o9123jaeoi;rg192h3ioear2 n369er3gr6n5es6n4v5369aei4jr53oise9n5liu43ejs5rgl3es5hgoi93645bsr3969g45n69.3l45ojg3;54ozd9h57v9l369n7dz5liv57hb639,hzkdh5v369nk,45hzd3fbvj5j3knfv969l3bak4uch93654ilar69fj45v369il4D5Svm936n,kzs93dvjn9ldisunv45936lisudsu45nv369u9s45din369vl5szd9vnb4kidsz9bv23iuzs6db2v394iuzdr3n5vb6uis3sn6v4biowi-6w45v3h;o-4i65h3v-;oi5w.H4-v5lj.s4-6hdv53vo6-4kbS35LDi69bv-435iS6D4HBc35liu9s4b53c9iS4B53cv 4935sdbz9i4563abes 6945g3bs4569vb45k,h6SDdv453hk6dszb639vi5h4bdisz6y54vb369.kS54D36v9bb54k,sz6vb453hkzdf45uvb36945zdiluuv45b369jkz.45sdh369v45kjzs369df45vi369n45aer36fh45f369i4uewr45yffh6if45a9368szduhf45va9lwei3624sjhf3624ieu32jhf36c 23,6k m4jzdm3hfbc 43ki2.aekrus69entpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Lesenfantsnesententpastrestresbonmaiscac'estparcequ'ilsfontcacadansleurculotteetquecen'estvraimentpastrestrespropreNonmongroscoupdecœurc'étaitunsoirde2005,j'étaisinvitéàuneconférenceàLaSorbonnepourparlerdelachansonfrancaiseetdel'écrituredetexteavecpleinsd'autresgens.ParmilesstarsémergentesilyavaitOliviaRuizquietaitentraindedevenirunestaravecsachansonsurlechocolatàlacon.Brefjeelretrouvecoincélorsd'une\"atelierderéflexion\"entreOliviaetRichardCrossquicommençaitàêtrepasmalconnudanslemilieuencemomentàcausedequelquesémissionsdeteréalité.J'aibienrigoleavecOliviaRuizcesoirlà,jeluiparlaitdemonrêved'écritetunechansondepirate,elledelafaçonqu'elleavaitd'écriredeschansons\"commeellessortaient\"etdes'étonnerparfoisqued'autrestrouventcabien.Brefçac'étaitunechouettesoirée/nuitquis'estterminéeauxalentoursde7hdumatinenprenantuncaféauChaidel'AbbayeprèsdeMabillon.Avantqu'ellenedisparaissepourtoujoursdemonexistence.JesuissouventrepasséauChaitôtlematinenespérantlarevoirmaisniet.Rien.JusteChristineScottThomasaperçuunjeudimatinoùilfaisaitchaud.Etalafinilla*bip*");
	// one time tests
	#endif
	return (0);
}
