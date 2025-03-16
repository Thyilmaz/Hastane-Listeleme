# Acil Servis Hasta Takip Sistemi

Bu proje, acil servis hastalarını **öncelik sırasına göre yönetmek** için bir **bağlı liste (linked list)** yapısını kullanarak oluşturulmuş basit bir C programıdır.

##  Özellikler
- **Yeni hasta ekleme**: Hasta bilgilerini ve öncelik seviyesini alarak listeye ekler.
- **Hasta çağırma**: Öncelik sırasına göre en önemli hastayı listeden çıkarır.
- **Bekleyen hastaları listeleme**: Mevcut hasta listesini ekrana yazdırır.
- **Bellek yönetimi**: Program çıkarken tüm hastaları bellekte temizler.


3. **Kullanıcı Arayüzü**
   Program çalıştırıldığında aşağıdaki menü görüntülenir:
   ```
   --- Acil Servis Sistemi ---
   1. Yeni Hasta Kaydı
   2. Hasta Çağır
   3. Bekleyen Hastaları Listele
   4. Çıkış
   ```
   Kullanıcı, istediği işlemi seçerek sistemle etkileşime geçebilir.

## 🔧 Fonksiyonlar

- **hastaEkle(char isim[], int yas, int oncelik):** Yeni hastayı önceliğine göre listeye ekler.
- **hastaCagir():** Öncelikli hastayı çıkarır ve bilgilerini ekrana yazdırır.
- **hastalariListele():** Mevcut hasta listesini ekrana yazdırır.
- **listeyiTemizle():** Programdan çıkarken tüm belleği temizler.

## 🎯 Öncelik Sistemi
| Öncelik | Açıklama |
|---------|------------|
| 1 | Yüksek Öncelik |
| 2 | Orta Öncelik |
| 3 | Düşük Öncelik |

Hastalar, **öncelik sırasına göre sıralanarak** listelenir ve çağrılır.

## 📜 Lisans
Bu proje açık kaynak olarak paylaşılmıştır.

