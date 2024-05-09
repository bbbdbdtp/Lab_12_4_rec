#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_12_4_rec/Main.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
    TEST_CLASS(UnitTest)
    {
    public:

        TEST_METHOD(TestCountPositiveElements)
        {
            // Arrange
            Node* head = nullptr;
            Node* tail = nullptr;
            int values[] = { 1, -2, 3, -4, 5 };
            int size = sizeof(values) / sizeof(values[0]);
            createCircularList(head, tail, values, size);

            // Act
            int count = countPositiveElements(head, head);

            // Assert
            Assert::AreEqual(3, count);
        }
    };
}
