??    G      T  a   ?        o     ?   ?  ?   ?  .   X  #   ?     ?  '   ?     ?     ?          +  (   :     c  K   z     ?     ?     ?  -   ?     	     ,	     4	     B	  8   Y	  M   ?	  k   ?	  8   L
  (   ?
     ?
     ?
  u   ?
     H     M  X   R  @   ?     ?       ;     6   [  7   ?  ?   ?  /   S  4   ?  =   ?  Y   ?  ?  P  )     7   >     v  1   ?  '   ?  .   ?  C     F  b     ?  ?   ?     D     J  n   j     ?  @   ?     3  &   P     w     z  '   ?     ?  !   ?     ?  a        m  ?  q  w   ?  9   n  ?   ?  5   ]  *   ?     ?  )   ?  	             %     =  '   P     x  O   ?     ?     ?  
     6        N     ^     f     u  9   ?  T   ?  r     ;   ?  %   ?     ?      ?  l        }     ?  p   ?  <   ?     6     I  <   e  <   ?  5   ?  ?     ,   ?  1   ?  ;     ^   L  ?  ?  .   ?!  >   ?!     "  +   %"  2   Q"  2   ?"  C   ?"  Q  ?"     M$  ?   i$     ?$  %   %  s   +%  !   ?%  D   ?%  !   &  /   (&     X&     \&  !   r&     ?&     ?&     ?&  i   ?&     M'        4      '       B                    >                       0      A                    ?       *                  (       3   =   ,   ;                 8   /   <   6               -      E   .   C           9       1                            +   2   #          D   G         :      %      7          !       $   "   )   
      F      	   5   @   &    
        --outdated		Merge in even outdated translations.
	--drop-old-templates	Drop entire outdated templates. 
  -o,  --owner=package		Set the package that owns the command.   -f,  --frontend		Specify debconf frontend to use.
  -p,  --priority		Specify minimum priority question to show.
       --terse			Enable terse mode.
 %s failed to preconfigure, with exit status %s %s is broken or not fully installed %s is fuzzy at byte %s: %s %s is fuzzy at byte %s: %s; dropping it %s is missing %s is missing; dropping %s %s is not installed %s is outdated %s is outdated; dropping whole template! %s must be run as root (Enter zero or more items separated by a comma followed by a space (', ').) Back Cannot read status file: %s Choices Config database not specified in config file. Configuring %s Debconf Debconf on %s Debconf, running at %s Dialog frontend is incompatible with emacs shell buffers Dialog frontend requires a screen at least 13 lines tall and 31 columns wide. Dialog frontend will not work on a dumb terminal, an emacs shell buffer, or without a controlling terminal. Enter the items you want to select, separated by spaces. Extracting templates from packages: %d%% Help Ignoring invalid priority "%s" Input value, "%s" not found in C choices! This should never happen. Perhaps the templates were incorrectly localized. More Next No usable dialog-like program is installed, so the dialog based frontend cannot be used. Note: Debconf is running in web mode. Go to http://localhost:%i/ Package configuration Preconfiguring packages ...
 Problem setting up the database defined by stanza %s of %s. TERM is not set, so the dialog frontend is not usable. Template #%s in %s does not contain a 'Template:' line
 Template #%s in %s has a duplicate field "%s" with new value "%s". Probably two templates are not properly separated by a lone newline.
 Template database not specified in config file. Template parse error near `%s', in stanza #%s of %s
 Term::ReadLine::GNU is incompatable with emacs shell buffers. The Sigils and Smileys options in the config file are no longer used. Please remove them. The editor-based debconf frontend presents you with one or more text files to edit. This is one such text file. If you are familiar with standard unix configuration files, this file will look familiar to you -- it contains comments interspersed with configuration items. Edit the file, changing any items as necessary, and then save it and exit. At that point, debconf will read the edited file, and use the values you entered to configure the system. This frontend requires a controlling tty. Unable to load Debconf::Element::%s. Failed because: %s Unable to start a frontend: %s Unknown template field '%s', in stanza #%s of %s
 Usage: debconf [options] command [args] Usage: debconf-communicate [options] [package] Usage: debconf-mergetemplate [options] [templates.ll ...] templates Usage: dpkg-reconfigure [options] packages
  -a,  --all			Reconfigure all packages.
  -u,  --unseen-only		Show only not yet seen questions.
       --default-priority	Use default priority instead of low.
       --force			Force reconfiguration of broken packages.
       --no-reload		Do not reload templates. (Use with caution.) Valid priorities are: %s You are using the editor-based debconf frontend to configure your system. See the end of this document for detailed instructions. _Help apt-extracttemplates failed: %s debconf-mergetemplate: This utility is deprecated. You should switch to using po-debconf's po2debconf program. debconf: can't chmod: %s delaying package configuration, since apt-utils is not installed falling back to frontend: %s must specify some debs to preconfigure no none of the above please specify a package to reconfigure template parse error: %s unable to initialize frontend: %s unable to re-open stdin: %s warning: possible database corruption. Will attempt to repair by adding back missing question %s. yes Project-Id-Version: debconf
Report-Msgid-Bugs-To: 
POT-Creation-Date: 2013-08-26 13:28-0400
PO-Revision-Date: 2010-03-08 18:40+0100
Last-Translator: Daniel Nylander <po@danielnylander.se>
Language-Team: Swedish <tp-sv@listor.tp-sv.se>
Language: sv
MIME-Version: 1.0
Content-Type: text/plain; charset=utf-8
Content-Transfer-Encoding: 8bit
X-Poedit-Bookmarks: 53,-1,-1,-1,-1,-1,-1,-1,-1,-1
 
        --outdated		Baka in även föråldrade översättningar.
	--drop-old-templates	Kasta alla föråldrade mallar. 
  -o,  --owner=paket		Sätt paketet som äger kommandot.   -f,  --frontend		Specificera framände att använda mot debconf.
  -p,  --priority		Specificera minimum prioritet för att visa frågor.
       --terse			Aktivera koncist läge.
 %s misslyckades med förkonfigurering, med slutkod %s %s är trasigt eller inte helt installerat %s är luddig vid byte %s: %s %s är luddig vid byte %s: %s; kastar den %s saknas %s saknas; kastar %s %s är inte installerat %s är föråldrad %s är föråldrad; kastar hela mallen! %s måste köras som root (Ange noll eller flera poster separerade med komma följt av blanksteg (", ").) Föregående Kan inte läsa statusfil: %s Alternativ Konfigurationsdatabas inte angiven i inställningsfil. Konfigurerar %s Debconf Debconf på %s Debconf på %s Dialogframänden är inkompatibel med emacs-skalbuffertar Dialogframänden kräver en skärm som är minst 13 rader hög och 31 kolumner bred. Dialogframänden fungerar inte på en dum terminal, i en emacs-skalbuffert, eller utan en kontrollerande terminal. Ange de alternativ du vill markera, avdelade med blanksteg. Plockar ut mallar från paketen: %d%% Hjälp Ignorerar ogiltig prioritet "%s" Indatavärde, "%s" hittades inte i C-val! Detta skall inte inträffa. Kanske översattes mallarna felaktigt. Mer Nästa Inget användbart dialogliknande program har installerats, så den dialogbaserade framänden kan inte användas. Obs: Debconf kör i webbläge. Gå till http://localhost:%i/ Paketkonfiguration Förkonfigurerar paket ...
 Problem med att skapa databasen som anges av strof %s av %s. TERM är inte satt, så dialogframänden kan inte användas. Mall %s i %s innehåller inte någon "Template:"-rad
 Mall %s i %s har ett dubblerat "%s"-fält med det nya värdet "%s". Det beror troligen på att två mallar inte avdelats korrekt med en ensam radbrytning.
 Malldatabas inte angiven i inställningsfil. Tolkningsfel nära "%s" i mall, i strof %s av %s
 Term::ReadLine::GNU kan inte användas i Emacs skalbuffert. Sigils- och Smileys-inställningarna i konfigurationsfilen används inte längre. Ta bort dem. Den redigerarbaserade debconf-framänden ger dig en eller flera textfiler att redigera. Detta är en sådan fil. Om du är van vid vanliga konfigurationsfiler i Unix kommer du känna igen formatet på den här filen -- den innehåller kommentarer med interfolierade konfigurationsposter. Redigera filen och ändra de poster som behövs, och spara och avsluta sedan. Vid den tidpunkten kommer debconf läsa den redigerade filen, och använda de värden du angivit för att konfigurera systemet. Denna framände kräver en kontrollerande tty. Kan inte ladda Debconf::Element::%s. Misslyckades eftersom: %s Kan inte starta framände: %s Okänt fält "%s" i mall, i strof %s av %s
 Användning: debconf [flaggor] kommando [argument] Användning: debconf-communicate [flaggor] [paket] Användning: debconf-mergetemplate [flaggor] [mallar.ll ...] mallar Användning: dpkg-reconfigure [flaggor] paket
  -a,  --all			Konfigurera om alla paket.
  -u,  --unseen-only		Visa bara osedda frågor.
       --default-priority	Använd standard prioritet istället för låg.
       --force			Tvinga omkonfigurering av trasiga paket.
       --no-reload		Läs inte om mallar. (Använd med försiktighet.) Giltiga prioriteter är: %s Du använder den redigerarbaserade debconf-framänden för att konfigurera ditt system. Se slutet av detta dokument för detaljerade instruktioner. _Hjälp apt-extracttemplates misslyckades: %s debconf-mergetemplate: Detta verktyg är föråldrat. Du bör byta till programmet po2debconf i paketet po-debconf. debconf: kan inte byta ägare: %s fördröjer paketkonfigurering eftersom apt-utils ej är installerat faller tillbaka på framände: %s måste ange några debpaket att förkonfigurera nej inget av ovanstående ange ett paket att konfigurera om malltolkfel: %s kan inte initiera framände: %s kan inte återöppna stdin: %s varning: databasen kan vara trasig. Försöker reparera genom att lägga tillbaka den saknade frågan %s. ja 