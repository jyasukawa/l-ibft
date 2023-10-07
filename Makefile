CC					= cc
CFLAGS			= -Wall -Wextra -Werror

SRCS				= ft_isalpha.c \
							ft_isdigit.c \
							ft_isalnum.c \
							ft_isascii.c \
							ft_isprint.c \
							ft_strlen.c \
							ft_memset.c \
							ft_bzero.c \
							ft_memcpy.c \
							ft_memmove.c \
							ft_strlcpy.c \
							ft_strlcat.c \
							ft_toupper.c \
							ft_tolower.c \
							ft_strchr.c \
							ft_strrchr.c \
							ft_strncmp.c \
							ft_memchr.c \
							ft_memcmp.c \
							ft_strnstr.c \
							ft_atoi.c \
							ft_calloc.c \
							ft_strdup.c \
							ft_substr.c \
							ft_strjoin.c \
							ft_strtrim.c \
							ft_split.c \
							ft_itoa.c \
							ft_strmapi.c \
							ft_striteri.c \
							ft_putchar_fd.c \
							ft_putstr_fd.c \
							ft_putendl_fd.c \
							ft_putnbr_fd.c

SRCS_BONUS	= ft_lstnew.c \
							ft_lstadd_front.c \
							ft_lstsize.c \
							ft_lstlast.c \
							ft_lstadd_back.c \
							ft_lstdelone.c \
							ft_lstclear.c \
							ft_lstiter.c \
							ft_lstmap.c

OBJS				= $(SRCS:.c=.o)
OBJS_BONUS	= $(SRCS_BONUS:.c=.o)
NAME				= libft.a

ifdef BONUS
  SRCS += $(SRCS_BONUS)
  OBJS += $(OBJS_BONUS)
endif

all:					${NAME}

$(NAME):			${OBJS}
							@ar -rcs $(NAME) ${OBJS}

bonus:				
							@$(MAKE) BONUS=1 all

%.o:					%.c
							$(CC) $(CFLAGS) -c $< -o $@

clean:
							rm -f ${OBJS} ${OBJS_BONUS}

fclean:				clean
							rm -f $(NAME)

re:						fclean all

.PHONY:				all bonus clean fclean re

# ＜Makefile作成時の慣習＞
# 通常、Makefileの冒頭でコンパイラ（CC）とコンパイラフラグ（CFLAGS）を定義する。
# 次に、ソースファイル（SOURCES）を指定する。
# 変数を定義する。
# ターゲット（ルール）を定義する。（allを一番上にするとよい）
# クリーンルールを定義する。
# 再ビルドルールを定義する。
# .PHONYを定義する。
# Makefile内で変数の定義順序は重要ですが、OBJS と NAME の順序を変更するだけでは、通常の動作には影響しません
# %.o: %.c ルールを一番下に書くことは、一般的な慣習とは異なりますが、技術的には問題ありません。Makefileは順番に評価されるため、このルールが後に定義されていても、正しく動作します。
# 上記の順序やルールは一般的な慣習ですが、Makefileは柔軟でカスタマイズ可能

# ＜このMakefileの説明＞
# OBJS		= $(SRCS:.c=.o)
# この行では、.c 拡張子を持つ各ファイル名を .o 拡張子に変更して OBJECTS 変数に格納します。
# 例）OBJS = file1.o file2.o file3.o
# このようにして、OBJECTS 変数には .o ファイルのリストが生成されます。
# ar コマンドは、アーカイブファイル（通常は拡張子 .a を持つ）を作成、操作、表示するために使用されます。
# 基本的な構文: ar [オプション] アーカイブファイル [ファイル1] [ファイル2] ...
# -r オプションは、アーカイブファイルにファイルを追加します。指定したアーカイブファイルが存在しない場合は新規に作成します。
# -c オプションは、アーカイブファイルが存在しない場合でも新しいアーカイブファイルを作成します。既存のアーカイブファイルがある場合、上書きせずに新しいアーカイブファイルを作成します。
# -s オプションは、アーカイブファイル内のオブジェクトファイル（.o ファイル）を再配置してサイズを最適化します。このオプションを使用することで、アーカイブファイルのサイズを最小限に抑えることができます。
# オブジェクトファイルの索引を書庫に書き込むか、または存在する索引を更新 する。書庫に何の変化がなくても更新は行われる。この修正子はどんな操作と も同時に用いることができるし、単独でも用いることができる。 `ar s ' を書庫に対して実行するのは、 `ranlib ' と等価である。
# 要するに、ar -s オプションはアーカイブファイルをより効率的に管理し、実行時およびビルド時のパフォーマンスを向上させるための重要なツールです。しかし、このオプションは一部の ar コマンドバージョンにしか存在しないことがあるため、使用前にドキュメンテーションやマニュアルを確認することをお勧めします。
# %.o: %.c
#     $(CC) $(CFLAGS) -c $< -o $@
# % はワイルドカード文字で、任意のファイル名を表します。
# .o: .c は .o ファイルを .c ファイルから生成することを意味します
# -c はコンパイラオプションの一つで、コンパイルフラグの一部
# Cソースコードをコンパイルし、オブジェクトファイル（.o ファイル）を生成しますが、リンクは行いません（以下makefile例参照）
# $< は依存する最初のファイル（ここでは .c ファイル）を表します
# $@ はターゲットの名前を表すここでは .o ファイル）を表します。
# このルールは、.c ファイルが変更された場合や依存関係が変更された場合にのみ再コンパイルされるため、ビルドプロセスの効率が向上する
# fcleanはcleanでオブジェクトファイルを削除したのち、ライブラリファイルを削除する
# reはfcleanしたのち、allを実行する
# .PHONY ターゲットを使用すると、Makeに対して特定のターゲットが実際のファイルやディレクトリではなく、単なる作業手順を表すことを伝えることができます。これにより、ターゲット名が既存のファイルと重複していても、Makeは正しく動作します。
# .PHONY を使用しない場合、clean という名前のファイルが存在すると、Makeは何もしない可能性があります。

# ＜relink＞
# target名と作成される実行ファイル名を同じにすることで、relinkが起きないようにすることができることがわかる。
# ifdef BONUS: この行は、BONUS という変数が定義されているかどうかをチェックしています。ifdef は、指定した変数が定義されている場合に条件が成立します。
# SRCS += $(SRCS_BONUS) と OBJS += $(OBJS_BONUS)：BONUS が定義されている場合、共通のソースコード SRCS にボーナス用のソースコード SRCS_BONUS を追加し、共通のオブジェクトファイル OBJS にボーナス用のオブジェクトファイル OBJS_BONUS を追加します。
# @$(MAKE) BONUS=1 all：bonus ターゲットが実行されると、$(MAKE) コマンドを使用して再帰的に all ターゲットを呼び出します。このとき、BONUS=1 という変数をセットしています。これにより、前述の条件式 ifdef BONUS でボーナス用のソースコードとオブジェクトファイルが追加され、最終的に ${NAME} ターゲット（通常は libft.a ライブラリの生成）がビルドされます。
# 要するに、bonus ターゲットを実行すると、ボーナス用のソースコードとオブジェクトファイルが追加されて通常の all ターゲットが実行され、最終的にはボーナスを含んだライブラリが生成される仕組みです。

# ＜そもそもMakefileって何＞
# main.cとsub.cという２つのソースから myprogramという実行バイナリを作成することを考えます
# % gcc main.c sub.c -o myprogram
# これだと，一方のファイルを修正しただけですべてのソースファイルのコンパイルが必要となってしまうので，
# % gcc -c main.c
# % gcc -c sub.c
# % gcc main.o sub.o -o myprogram
# と別々にオブジェクトファイルを作成して， 最後にリンクしたほうが効率がいい
# Makefileにすると以下のようになります
# myprogram: main.o sub.o
#            gcc -o myprogram main.o sub.o
# main.o:    main.c
#            gcc -c main.c
# sub.o:     sub.c
#            gcc -c sub.c
# -c オプションを使用せずにコンパイルすると、Cソースコードがコンパイルされ、オブジェクトファイルが生成され、リンク処理も行われ、最終的に実行可能なプログラムが生成されます。
# -c オプションを使用すると、Cソースコードがコンパイルされ、オブジェクトファイル（.o ファイル）が生成されますが、リンクは行いません。これにより、コンパイルとリンクを分離して実行することができます。これは大規模なプロジェクトのビルドや再コンパイルの高速化に役立ちます。
# make（作る）という意味
# install:        $(PROGRAM)
#                 install -s $(PROGRAM) $(DEST)
# installしろ」という意味で make install と実行しますが， makeとしては「installを作成しろ」と解釈します． installを作成するためには $(PROGRAM)が必要であり （なければ作成します）
# 結局，installというものは作成できていないわけですが， 目的は果たしたことになります．
# all:            $(PROGRAM)
# llを作りたければ，まず$(PROGRAM)を作れという意味しかありません． これは， 作りたいものを指定せずに makeコマンドを実行すると 一番最初にある[作りたいもの]が作成される ことを利用して， とりあえず make と入力すれば実行バイナリが作成されるようにするための仕掛けです． このルールは，一番最初に書かないと意味がありません

# ＜暗黙のルール＞
# main.cと sub.cから， それぞれ main.o と sub.oを作成する方法を書いていませんでした． 通常 *.cから *.oの作成手順は省略します
# *.cから *.oが自動的に作成される際に，CFLAGSがオプションとして使われます．
# CFLAGSにもデフォルトが存在する