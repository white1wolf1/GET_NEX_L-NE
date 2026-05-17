*This project has been created as part of the 42 curriculum by asobolev*

# Get_Next_Line

## Açıklama

Bu repo `get_next_line` fonksiyonunun (ve yardımcı fonksiyonların)
örnek implementasyonunu içerir. Amaç, bir dosya tanımlayıcısından satır
satır okuma yapmak ve her çağrıda bir satır döndürmektir (sonunda '\n' varsa
satır dahil). Proje 42 müfredatına göre hazırlanmıştır.

## İçerik

- get_next_line.c
- get_next_line_utils.c
- get_next_line.h

## Kurulum & Derleme

Geliştirme ortamında standart GCC ile derlemek için örnek komut:

```bash
gcc -D BUFFER_SIZE=32 -Wall -Wextra -Werror -I. get_next_line.c get_next_line_utils.c -o gnl_test
```

`BUFFER_SIZE` makrosunu ihtiyaca göre değiştirin (örnekte 32).

## Kullanım

Derlenen ikiliyi bir dosya ile çalıştırın:

```bash
./gnl_test input.txt
```

Fonksiyon prototipi:

```c
char *get_next_line(int fd);
```

Davranış:
- Başarılıysa heap üzerinde ayrılmış bir satır döndürür (sonunda '\n' bulunuyorsa dahil).
- Dosya sonu veya hata durumunda `NULL` döner.

Kullanıcı çağrısı satırı serbest bırakmaktan sorumludur.

## Fonksiyonlar / Teknik Detaylar

- `get_next_line(int fd)` : Verilen `fd` için bir sonraki satırı döndürür.
- Yardımcı fonksiyonlar: `ft_strdup`, `ft_strjoin`, `ft_substr`, `ft_strlen`, `ft_strchr` (util dosyasında kullanılıyor).
- Statik bir `storage` kullanılarak, okunup kalan veri bir sonraki çağrıda korunur.

## Hata Yönetimi ve Sınırlar

- `fd` < 0 veya `BUFFER_SIZE` < 1 durumunda `NULL` döner.
- `read()` hata verirse tüm ilgili bellek temizlenir ve `NULL` döner.
- Her döndürülen satır caller tarafından `free()` edilmeli.

## Testler & Stil Denetimi

- Norminette stil kurallarına uymak için `norminette` çalıştırın:

```bash
norminette .
```

- Birim testleri bulunmamaktadır; basit bir `main` ile manuel test edebilirsiniz.

## Katkıda Bulunma

Pull request'ler ve hata bildirimleri memnuniyetle karşılanır. Değişiklik gönderirken
kodun derlendiğini ve temel testlerin geçtiğini doğrulayın.

## Lisans

Bu proje açık kaynaklıdır — lisans bilgisi eklemek isterseniz `LICENSE` dosyası oluşturun.

## Kaynaklar

- 42 Network get_next_line ödevi yönergeleri
- Proje içinde kullanılan yardımcı fonksiyonlar kendi implementasyonunuz olmalıdır.

## Ai usage

Bu repoda oluşturulan metin veya açıklamalar AI araçları kullanılarak üretilmiş olabilir; kod
ve mantık elle yazılmıştır.