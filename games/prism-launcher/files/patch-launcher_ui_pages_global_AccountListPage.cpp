--- launcher/ui/pages/global/AccountListPage.cpp.orig	2023-11-21 15:45:10 UTC
+++ launcher/ui/pages/global/AccountListPage.cpp
@@ -146,6 +146,7 @@ void AccountListPage::on_actionAddOffline_triggered()
 
 void AccountListPage::on_actionAddOffline_triggered()
 {
+#ifdef NO_OFFLINE
     if (!m_accounts->anyAccountIsValid()) {
         QMessageBox::warning(this, tr("Error"),
                              tr("You must add a Microsoft account that owns Minecraft before you can add an offline account."
@@ -153,6 +154,7 @@ void AccountListPage::on_actionAddOffline_triggered()
                                 "If you have lost your account you can contact Microsoft for support."));
         return;
     }
+#endif
 
     MinecraftAccountPtr account =
         OfflineLoginDialog::newAccount(this, tr("Please enter your desired username to add your offline account."));
