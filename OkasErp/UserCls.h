#ifndef USERCLS_H
#define USERCLS_H
#include <QString>

typedef struct
{
    /** @brief Holds true for negative values */
        uint32_t m_ulnID;
        /** @brief Holds true for negative values */
        QString m_UserNameStr;
        /** @brief Holds true for negative values */
        QString m_EmailStr;
        /** @brief Holds true for negative values */
        QString m_PasswordStr;
        /** @brief Holds true for negative values */
        bool m_blnProductTrackingAuth;
        /** @brief Holds true for negative values */
        bool m_blnBrandingAuth;
        /** @brief Holds true for negative values */
        bool m_blnCustomerAuth;
        /** @brief Holds true for negative values */
        bool m_blnUserAuth;
        /** @brief Holds true for negative values */
        bool m_blnSalesAuth;
} UserStc;

#endif // USERCLS_H
