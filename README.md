 Lojistik Ağ ve Dinamik Paket Yönetim SistemiBu proje, bir lojistik ağındaki şehirler arası rotaların yönetimi ve paketlerin bellek üzerinde hash tablosu ile takip edilmesini simüle eden, C programlama dili ile geliştirilmiş bir veri yapıları projesidir.
 
 🚀 Proje HakkındaSistem, karmaşık lojistik operasyonlarını iki temel veri yapısı kullanarak çözer:Lojistik Graf Yapısı: Şehirleri düğüm (node), aralarındaki yolları ise kenar (edge) olarak modeller. Şehirler arası en kısa rota BFS (Breadth-First Search) algoritması kullanılarak hesaplanır.Dinamik Hash Tablosu: Paketleri (TR101, TR102 vb.) hızlı erişim için bellek üzerinde adresler. Çakışma yönetimi için Açık Adresleme (Linear Probing) yöntemi ve Tip B Hash Fonksiyonu kullanılmıştır
 
 .🛠️ Kullanılan Teknolojiler ve AraçlarDil: C (Memory Management, Pointers, Structs)IDE: JetBrains CLionAlgoritmalar: BFS (Gezinti), Hash Mapping, Queue ManagementTasarım: draw.io (Sistem Mimarisi Görselleştirme)

 📊 Sistem Mimarisi ve Bellek HaritasıProje kapsamında oluşturulan bellek hiyerarşisi, RAM üzerindeki pointer bağlantılarını şematik olarak göstermektedir.BileşenVeriBellek Adresi (Örnek)Hash TableRoot000001bd4d835910Paket (P1)TR101000001bd4d835b18Şehir (Düğüm)Istanbul000001bd4d831490Not: Detaylı bellek analizleri ve pointer bağlantıları proje raporunda sunulmuştur.
 
 📂 Dosya Yapısımain.c: Programın ana akışını ve kullanıcı arayüzünü yönetir.logistics.h: Graf ve Hash yapılarının tanımlarını içerir.logistics.c: Algoritmaların (BFS, Hash Search) implementasyonunu içerir.
