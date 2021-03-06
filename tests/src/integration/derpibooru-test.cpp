#include <QtTest>
#include <QStringList>
#include "derpibooru-test.h"
#include "functions.h"


void DerpibooruTest::testHtml()
{
	QList<Image*> images = getImages("Booru-on-rails", "derpibooru.org", "regex", "safe", "results.html");

	// Convert results
	QList<int> ids;
	for (Image *img : images)
	{
		ids.append(img->id());
	}

	// Check results
	ids = ids.mid(0, 3);
	QList<int> expected = QList<int>() << 1334191 << 1334187 << 1334186;
	QCOMPARE(images.count(), 15);
	QCOMPARE(ids, expected);
}

void DerpibooruTest::testJson()
{
	QList<Image*> images = getImages("Booru-on-rails", "derpibooru.org", "json", "safe", "results.json");

	// Convert results
	QList<int> ids;
	for (Image *img : images)
	{
		ids.append(img->id());
	}

	// Check results
	ids = ids.mid(0, 3);
	QList<int> expected = QList<int>() << 1248664 << 1248663 << 1248661;
	QCOMPARE(images.count(), 15);
	QCOMPARE(ids, expected);
}


static DerpibooruTest instance;
