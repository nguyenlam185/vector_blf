#define BOOST_TEST_MODULE AppText
#if !defined(WIN32)
#define BOOST_TEST_DYN_LINK
#endif
#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include "Vector/BLF.h"

/* APP_TEXT = 65 */
BOOST_AUTO_TEST_CASE(AppText)
{
    Vector::BLF::File file;
    file.open(CMAKE_CURRENT_SOURCE_DIR "/events/test_AppText.blf");
    BOOST_REQUIRE(file.is_open());

    Vector::BLF::ObjectHeaderBase * ohb;
    ohb = file.read();
    BOOST_REQUIRE(ohb != nullptr);
    BOOST_REQUIRE(ohb->objectType == Vector::BLF::ObjectType::APP_TEXT);
    Vector::BLF::AppText * obj;
    obj = static_cast<Vector::BLF::AppText *>(ohb);

    /* ObjectHeaderBase */
    BOOST_CHECK_EQUAL(obj->signature, Vector::BLF::ObjectSignature);
    BOOST_CHECK_EQUAL(obj->headerSize, obj->calculateHeaderSize());
    BOOST_CHECK_EQUAL(obj->headerVersion, 1);
    BOOST_CHECK_EQUAL(obj->objectSize, obj->calculateObjectSize());
    BOOST_CHECK(obj->objectType == Vector::BLF::ObjectType::APP_TEXT);

    /* ObjectHeader */
    BOOST_CHECK(obj->objectFlags == Vector::BLF::ObjectHeader::TimeOneNans);
    BOOST_CHECK_EQUAL(obj->clientIndex, 0x2222);
    BOOST_CHECK_EQUAL(obj->objectVersion, 0);
    BOOST_CHECK_EQUAL(obj->objectTimeStamp, 0x3333333333333333);

    /* AppText */
    BOOST_CHECK(obj->source == Vector::BLF::AppText::Source::MetaData);
    BOOST_CHECK_EQUAL(obj->reserved1, 0);
    BOOST_CHECK_EQUAL(obj->textLength, 4);
    BOOST_CHECK_EQUAL(obj->reserved2, 0);
    BOOST_CHECK_EQUAL(obj->text, "test");

    delete obj;

    file.close();
}
