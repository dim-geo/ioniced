# Copyright 1999-2005 Gentoo Foundation
# Distributed under the terms of the GNU General Public License v2

DESCRIPTION="A ionice daemon"
HOMEPAGE="http://www.darav.de/schedtoold.html"
SRC_URI="http://www.darav.de/${P}.tar.bz2"
LICENSE="GPL-2"
SLOT=0
KEYWORDS="~x86 ~ppc ~amd64"
IUSE=""
DEPEND="sys-apps/util-linux"

src_unpack() {
	unpack ${A}
	cd ${S}
	sed -i 's:/usr/bin/:${D}/usr/bin/:' Makefile
}

src_compile() {
	emake || die "Compilation failed."
}

src_install() {

    mkdir -p ${D}/usr/bin
	make install
	dodoc ChangeLog COPYING AUTHORS README example/ioniced.conf

	insinto /etc/ ; newins example/ioniced.conf ioniced.conf
	exeinto /etc/init.d ; newexe init-scripts/gentoo/ioniced ioniced
}


